const fs = require('fs');
const csv = require('csv-parser');
const path = require('path');

const tableFilePath = path.join(__dirname, 'table.csv');
const inputFilePath = path.join(__dirname, 'input.txt');

const parseCSV = (filePath) => {
  return new Promise((resolve, reject) => {
    const results = [];
    fs.createReadStream(filePath)
      .pipe(csv())
      .on('data', (data) => results.push(data))
      .on('end', () => resolve(results))
      .on('error', (error) => reject(error));
  });
};

const readInput = (filePath) => {
  return fs.readFileSync(filePath, 'utf8').trim();
};

const parseTable = (table) => {
  const parsedTable = {};
  table.forEach((row) => {
    const nonTerminal = row.NonTerminal;
    if (!parsedTable[nonTerminal]) {
      parsedTable[nonTerminal] = {};
    }
    Object.keys(row).forEach((key) => {
      if (key !== 'NonTerminal' && row[key]) {
        parsedTable[nonTerminal][key] = row[key];
      }
    });
  });
  return parsedTable;
};

const parseInput = (input, table) => {
  const stack = ['$', 'S'];
  let pointer = 0;

  while (stack.length > 0) {
    const top = stack.pop();
    const current = input[pointer];

    if (top === '$' && current === '$') {
      return true;
    }

    if (top === current) {
      pointer++;
    } else if (table[top] && table[top][current]) {
      const production = table[top][current].split(' ');
      console.log(`Produção encontrada para ${top}: ${production}`);
      for (let i = production.length - 1; i >= 0; i--) {
        if (production[i] !== 'ε') {
          stack.push(production[i]);
        }
      }
    } else if (!table[top] && top !== current) {
      console.log(`Erro de sintaxe: esperado ${top}, encontrado ${current}`);
      return false;
    } else {
      console.log(`Erro de sintaxe: produção ausente para ${top} com terminal ${current}`);
      return false;
    }
  }

  return pointer === input.length - 1;
};

const main = async () => {
  try {
    const table = await parseCSV(tableFilePath);
    const input = readInput(inputFilePath) + '$';
    const parsedTable = parseTable(table);

    const result = parseInput(input, parsedTable);
    if (result) {
      console.log('Análise sintática concluída com sucesso!');
    } else {
      console.log('Erro durante a análise sintática.');
    }
  } catch (error) {
    console.error('Erro ao processar arquivos:', error);
  }
};

main();
