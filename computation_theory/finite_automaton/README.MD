# Relatório de Implementação: Simulador de Autômatos Finitos

A ferramenta é um simulador de autômatos finitos. Ela é capaz de ler a descrição de um autômato a partir de um arquivo JSON, bem como uma série de entradas a serem testadas a partir de um arquivo CSV. Com base nas transições e estados do autômato fornecido, a ferramenta simula a execução do autômato para cada entrada e registra os resultados, incluindo se a entrada é aceita ou rejeitada pelo autômato, o resultado esperado, o tempo de execução e outros detalhes relevantes. O simulador suporta autômatos determinísticos, não determinísticos e não determinísticos com transições vazias (ε-transitions).

## Principais Componentes e Funcionalidades

### Leitura de Arquivos

A ferramenta pode ler arquivos no formato JSON para descrever a estrutura do autômato e no formato CSV para fornecer entradas e resultados esperados.

### Execução do Autômato

O simulador executa o autômato para cada entrada fornecida. Dependendo das características do autômato (determinístico, não determinístico, ε-transitions), ele usa a função apropriada para simular a execução.

### Simulação de Autômatos

A ferramenta é capaz de simular autômatos determinísticos, não determinísticos e não determinísticos com ε-transitions. Ela utiliza algoritmos específicos para cada tipo de autômato.

### Medição do Tempo de Execução

O simulador registra o tempo de execução para cada entrada, permitindo que você saiba quanto tempo o autômato levou para processar cada entrada.

### Geração de Saída

Os resultados da simulação são gravados em um arquivo de saída, seguindo o formato especificado.

## Exemplificação

AFD

JSON: 

{
  "initial": 0,
  "final": [2],
  "transitions": [
    { "from": 0, "to": 0, "read": "b" },
    { "from": 0, "to": 1, "read": "a" },
    { "from": 1, "to": 2, "read": "b" }
  ]
}

CSV:

a;0
aa;0
aaaa;0
bbbab;1
ab;1

SAÍDA:

a;0;0;0.199
aa;0;0;0.018
aaaa;0;0;0.017
bbbab;1;1;0.007
ab;1;1;0.195

AFND

JSON:

{
  "initial": 0,
  "final": [2],
  "transitions": [
    { "from": 0, "to": 0, "read": "b" },
    { "from": 0, "to": 0, "read": "a" },
    { "from": 0, "to": 1, "read": "a" },
    { "from": 1, "to": 2, "read": "b" }
  ]
}

CSV:

a;0
aa;0
ababab;1
bbbab;1
ab;1

SAÍDA:

a;0;0;0.247
aa;0;0;0.025
ababab;1;1;0.033
bbbab;1;1;0.220
ab;1;1;0.024
