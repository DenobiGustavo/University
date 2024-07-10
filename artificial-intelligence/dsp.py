import heapq

class Grafo:
    def __init__(self):
        self.adjacencias = {}

    def adicionar_aresta(self, origem, destino):
        """Adiciona uma aresta bidirecional ao grafo."""
        if origem not in self.adjacencias:
            self.adjacencias[origem] = []
        if destino not in self.adjacencias:
            self.adjacencias[destino] = []
        self.adjacencias[origem].append(destino)
        self.adjacencias[destino].append(origem)  # Para bidirecionalidade (opcional)

def busca_custo_uniforme(origem, destino, grafo):
    """Executa o algoritmo de busca de custo uniforme (Dijkstra para menor número de cidades)."""
    fronteira = []  # Usaremos uma lista como fila de prioridade
    heapq.heappush(fronteira, (0, origem))  # (custo_atual, cidade_atual)
    visitados = set()  # Conjunto para manter as cidades visitadas

    while fronteira:
        custo_atual, cidade_atual = heapq.heappop(fronteira)

        if cidade_atual == destino:
            # Se chegamos ao destino, reconstruímos o caminho e retornamos
            return reconstruir_caminho(cidade_atual, origem, grafo)

        if cidade_atual not in visitados:
            visitados.add(cidade_atual)  # Marca a cidade como visitada
            # Explora todas as cidades adjacentes
            for cidade_adjacente in grafo.adjacencias.get(cidade_atual, []):
                if cidade_adjacente not in visitados:
                    novo_custo = custo_atual + 1  # Custo é o número de cidades no caminho
                    heapq.heappush(fronteira, (novo_custo, cidade_adjacente))

    return None  # Caminho não encontrado

def reconstruir_caminho(destino, origem, grafo):
    """Reconstrói o caminho do destino de volta à origem usando o grafo."""
    caminho = []
    cidade = destino
    while cidade != origem:
        caminho.append(cidade)
        # Aqui você pode modificar grafo[cidade].cidade_anterior para recuperar a cidade anterior
        # Se desejar manter o controle do caminho completo.
        cidade = grafo.adjacencias[cidade][0]  # Simplificação para o exemplo
    caminho.append(origem)
    caminho.reverse()  # Reverte a lista para obter o caminho da origem ao destino
    return caminho

# Exemplo de uso
grafo = Grafo()
grafo.adicionar_aresta('A', 'B')
grafo.adicionar_aresta('A', 'C')
grafo.adicionar_aresta('B', 'D')
grafo.adicionar_aresta('C', 'E')
grafo.adicionar_aresta('D', 'F')
grafo.adicionar_aresta('E', 'F')

origem = 'A'
destino = 'F'

# Executa a busca de custo uniforme no grafo
caminho = busca_custo_uniforme(origem, destino, grafo)

if caminho:
    print(f"Caminho encontrado de {origem} para {destino}: {caminho}")
else:
    print(f"Caminho não encontrado de {origem} para {destino}")