const fs = require("fs");

function readJSONFile(filename) {
  const data = fs.readFileSync(filename);
  return JSON.parse(data);
}

function readCSVFile(filename) {
  const data = fs.readFileSync(filename, "utf-8").toString();
  const lines = data.trim().split("\n");
  const entries = [];

  for (const line of lines) {
    const [input, expected] = line.split(";");
    const e = expected[0];
    entries.push({ input, expected: e });
  }

  return entries;
}

function runAutomatonDFA(automaton, input) {
  let currentState = automaton.initial;

  for (const char of input) {
    const transition = automaton.transitions.find(
      (t) => t.from === currentState && t.read === char
    );
    if (!transition) return false;
    currentState = transition.to;
  }

  return automaton.final.includes(currentState);
}

function runAutomatonNFA(automaton, input) {
  let currentStates = [automaton.initial];

  for (const char of input) {
    const nextStates = [];
    for (const state of currentStates) {
      const transitions = automaton.transitions.filter(
        (t) => t.from === state && (t.read === char || t.read === "")
      );
      nextStates.push(...transitions.map((t) => t.to));
    }
    currentStates = nextStates;
  }

  return currentStates.some((state) => automaton.final.includes(Number(state)));
}

function runAutomatonNFANull(automaton, input) {
  let currentStates = [automaton.initial];

  for (const char of input) {
    const nextStates = [];
    for (const state of currentStates) {
      const transitions = automaton.transitions.filter(
        (t) => t.from === state && (t.read === char || t.read === "")
      );
      nextStates.push(...transitions.map((t) => t.to));
    }
    currentStates = nextStates;
  }

  let updated = true;
  while (updated) {
    updated = false;
    const epsilonTransitions = automaton.transitions.filter(
      (t) => t.from === currentStates[0] && t.read === ""
    );
    const epsilonStates = epsilonTransitions.map((t) => t.to);
    if (epsilonStates.length > 0) {
      currentStates.push(...epsilonStates);
      updated = true;
    }
  }

  return currentStates.some((state) => automaton.final.includes(Number(state)));
}

function main() {
  if (process.argv.length !== 5) {
    console.log(
      "Uso: node simulador.js arquivo_do_automato.aut arquivo_de_testes.in arquivo_de_saida.out"
    );
    return;
  }

  const automaton = readJSONFile(process.argv[2]);
  const testEntries = readCSVFile(process.argv[3]);

  const results = [];

  for (const entry of testEntries) {
    const startTime = process.hrtime();

    let result;
    if (isNonDeterministic(automaton)) {
      result = runAutomatonNFA(automaton, entry.input);
    } else if (hasEpsilonTransitions(automaton)) {
      result = runAutomatonNFANull(automaton, entry.input);
    } else {
      result = runAutomatonDFA(automaton, entry.input);
    }

    const endTime = process.hrtime(startTime);
    const elapsedTime = endTime[0] * 1000 + endTime[1] / 1000000;

    results.push({
      input: entry.input,
      expected: entry.expected,
      result: result ? "1" : "0",
      time: elapsedTime.toFixed(3),
    });
  }

  const outputContent = results
    .map((r) => `${r.input};${r.expected};${r.result};${r.time}`)
    .join("\n");
  fs.writeFileSync(process.argv[4], outputContent);

  console.log("Simulação concluída. Resultados escritos em arquivo de saída.");
}

function isNonDeterministic(automaton) {
  const transitionsMap = new Map();

  for (const transition of automaton.transitions) {
    const key = `${transition.from}-${transition.read}`;
    if (transitionsMap.has(key)) {
      return true;
    }
    transitionsMap.set(key, transition.to);
  }

  return false;
}

function hasEpsilonTransitions(automaton) {
  return automaton.transitions.some((t) => t.read === "");
}

main();
