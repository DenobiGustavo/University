from collections import deque

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

def busca_em_largura(origem, destino, grafo):
    """Executa o algoritmo de Busca em Largura (BFS) para encontrar o caminho mais curto em número de cidades."""
    fila = deque([(origem, [origem])])  # (cidade_atual, caminho_percorrido)
    visitados = set()

    while fila:
        cidade_atual, caminho = fila.popleft()

        if cidade_atual == destino:
            return caminho  # Retorna o caminho quando alcança o destino

        if cidade_atual not in visitados:
            visitados.add(cidade_atual)
            for cidade_adjacente in grafo.adjacencias.get(cidade_atual, []):
                if cidade_adjacente not in visitados:
                    fila.append((cidade_adjacente, caminho + [cidade_adjacente]))

    return None  # Retorna None se não encontrar um caminho

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

caminho = busca_em_largura(origem, destino, grafo)

if caminho:
    print(f"Caminho encontrado de {origem} para {destino}: {caminho}")
else:
    print(f"Caminho não encontrado de {origem} para {destino}")