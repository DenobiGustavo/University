from collections import deque

def bfs(start, goal, grid):
    rows, cols = len(grid), len(grid[0])
    queue = deque([(start, [])])
    visited = set()
    visited.add(start)
    
    while queue:
        (x, y), path = queue.popleft()
        
        if (x, y) == goal:
            return path + [(x, y)]
        
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != '#' and (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append(((nx, ny), path + [(x, y)]))
    
    return None

def find_closest_pellet(pacman, pellets, grid):
    closest_pellet = None
    shortest_path = None
    
    for pellet in pellets:
        path = bfs(pacman, pellet, grid)
        if path and (shortest_path is None or len(path) < len(shortest_path)):
            closest_pellet = pellet
            shortest_path = path
    
    return closest_pellet, shortest_path

def pacman_bfs(grid):
    pacman = None
    pellets = []
    
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 'P':
                pacman = (i, j)
            elif grid[i][j] == 'B':
                pellets.append((i, j))
    
    while pellets:
        closest_pellet, path = find_closest_pellet(pacman, pellets, grid)
        if not path:
            break
        
        for step in path[1:]:
            pacman = step
            print(f"Move to {pacman}")
        
        pellets.remove(closest_pellet)
        grid[closest_pellet[0]][closest_pellet[1]] = '.'

# Exemplo de labirinto
grid = [
    "#######",
    "#P..B.#",
    "#.##..#",
    "#....B#",
    "#######"
]

# Transformar grid em lista de listas
grid = [list(row) for row in grid]

pacman_bfs(grid)
