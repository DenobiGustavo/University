# Simulador de Autômatos Finitos

O Simulador de Autômatos Finitos é uma ferramenta capaz de simular a execução de autômatos finitos a partir de descrições fornecidas em arquivos JSON, bem como testar uma série de entradas definidas em um arquivo CSV. A ferramenta suporta autômatos determinísticos, não determinísticos e não determinísticos com transições vazias (ε-transitions). Este documento descreve os principais componentes e funcionalidades do simulador.

## Funcionalidades

### Leitura de Arquivos

A ferramenta pode ler arquivos no formato JSON para descrever a estrutura do autômato e no formato CSV para fornecer entradas e resultados esperados.

Exemplo de JSON:

```json
{
  "initial": 0,
  "final": [2],
  "transitions": [
    { "from": 0, "to": 0, "read": "b" },
    { "from": 0, "to": 1, "read": "a" },
    { "from": 1, "to": 2, "read": "b" }
  ]
}
Exemplo de CSV:

csv
Copy code
a;0
aa;0
aaaa;0
bbbab;1
ab;1
Execução do Autômato
O simulador executa o autômato para cada entrada fornecida. Dependendo das características do autômato (determinístico, não determinístico, ε-transitions), ele usa a função apropriada para simular a execução.

Simulação de Autômatos
A ferramenta é capaz de simular autômatos determinísticos, não determinísticos e não determinísticos com ε-transitions. Ela utiliza algoritmos específicos para cada tipo de autômato.

Medição do Tempo de Execução
O simulador registra o tempo de execução para cada entrada, permitindo que você saiba quanto tempo o autômato levou para processar cada entrada.

Geração de Saída
Os resultados da simulação são gravados em um arquivo de saída, seguindo o formato especificado.

Exemplo de Saída:

csv
Copy code
Entrada;Resultado Obtido;Resultado Esperado;Tempo de Execução
a;0;0;0.199
aa;0;0;0.018
aaaa;0;0;0.017
bbbab;1;1;0.007
ab;1;1;0.195
Exemplificação
Autômato Finito Determinístico (AFD)
JSON:

json
Copy code
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

csv
Copy code
a;0
aa;0
aaaa;0
bbbab;1
ab;1
Saída:

csv
Copy code
Entrada;Resultado Obtido;Resultado Esperado;Tempo de Execução
a;0;0;0.199
aa;0;0;0.018
aaaa;0;0;0.017
bbbab;1;1;0.007
ab;1;1;0.195
Autômato Finito Não Determinístico (AFND)
JSON:

json
Copy code
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

csv
Copy code
a;0
aa;0
ababab;1
bbbab;1
ab;1
Saída:

csv
Copy code
Entrada;Resultado Obtido;Resultado Esperado;Tempo de Execução
a;0;0;0.247
aa;0;0;0.025
ababab;1;1;0.033
bbbab;1;1;0.220
ab;1;1;0.024
Conclusão
O Simulador de Autômatos Finitos é uma ferramenta poderosa para testar e entender o comportamento de diferentes tipos de autômatos. Ele oferece a capacidade de ler descrições de autômatos a partir de arquivos JSON e testar suas funcionalidades com entradas definidas em arquivos CSV. Com seu suporte a autômatos determinísticos, não determinísticos e não determinísticos com ε-transitions, ele é uma ferramenta versátil para estudar autômatos e suas aplicações.
