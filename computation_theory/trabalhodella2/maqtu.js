const fs = require('fs');

function lerEspecificacoes(nomeArquivo) {
    const especificacoes = fs.readFileSync(nomeArquivo, 'utf8');
    return JSON.parse(especificacoes);
}

function lerProblema(nomeArquivo) {
    const problema = fs.readFileSync(nomeArquivo, 'utf8');
    return problema.trim().split('');
}

function executarMaquinaTuring(especificacoes, fitaEntrada) {
    let estadoAtual = especificacoes.initial;
    let posicaoCabecote = 0;

    while (!especificacoes.final.includes(estadoAtual)) {
        const simboloAtual = fitaEntrada[posicaoCabecote] || especificacoes.white;

        const transicao = especificacoes.transitions.find(t =>
            t.from === estadoAtual && t.read === simboloAtual
        );

        if (!transicao) {
            break;
        }

        estadoAtual = transicao.to;

        if (transicao.write) {
            fitaEntrada[posicaoCabecote] = transicao.write;
        }

        if (transicao.dir === "R") {
            posicaoCabecote++;
        } else if (transicao.dir === "L") {
            posicaoCabecote = Math.max(0, posicaoCabecote - 1);
        }

        if (posicaoCabecote === fitaEntrada.length) {
            fitaEntrada.push(especificacoes.white);
        } else if (posicaoCabecote === -1) {
            fitaEntrada.unshift(especificacoes.white);
            posicaoCabecote = 0;
        }
    }

    return {
        fitaSaida: fitaEntrada.join(''),
        aceita: especificacoes.final.includes(estadoAtual),
    };
}

function salvarSaida(fitaSaida, nomeArquivo) {
    fs.writeFileSync(nomeArquivo, fitaSaida);
}

function main() {
    const especificacoes = lerEspecificacoes(process.argv[2]);
    const fitaEntrada = lerProblema(process.argv[3]);

    const resultado = executarMaquinaTuring(especificacoes, fitaEntrada);

    salvarSaida(resultado.fitaSaida, "saida.txt");

    console.log(resultado.aceita ? "1" : "0");
}

if (process.argv.length < 4) {
    console.error("Uso: node maquina_turing.js arquivo_especificacoes.json arquivo_problema.txt");
    process.exit(1);
}

main();
