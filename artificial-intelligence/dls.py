def depth_limited_search(graph, start, goal, limit):
    def dls(node, goal, limit, path):
        if limit == 0:
            return None
        if node == goal:
            return path + [node]
        for neighbor in graph[node]:
            if neighbor not in path:  # Evitar ciclos
                result = dls(neighbor, goal, limit - 1, path + [node])
                if result is not None:
                    return result
        return None

    return dls(start, goal, limit, [])

# Exemplo de Grafo de Cidades
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# Entrada do Usuário
start_city = 'A'  # Cidade de origem
end_city = 'F'    # Cidade de destino

# Iterative Deepening Depth-Limited Search
def iterative_deepening_dls(graph, start, goal):
    depth = 1
    while True:
        path = depth_limited_search(graph, start, goal, depth)
        if path:
            return path
        depth += 1

# Executar o IDDFS adaptado
path = iterative_deepening_dls(graph, start_city, end_city)

if path:
    print(f"O caminho mais curto de {start_city} a {end_city} é: {' -> '.join(path)}")
else:
    print(f"Não há caminho de {start_city} a {end_city}")

