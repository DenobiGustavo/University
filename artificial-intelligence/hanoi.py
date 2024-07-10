from collections import deque
import time

class Hanoi:
    def __init__(self, num_discs):
        self.num_discs = num_discs
        self.initial_state = (tuple(range(num_discs, 0, -1)), (), ())
        self.goal_state = ((), (), tuple(range(num_discs, 0, -1)))
    
    def is_goal(self, state):
        return state == self.goal_state
    
    def get_successors(self, state):
        successors = []
        for i in range(3):
            if not state[i]:
                continue
            disc = state[i][-1]
            for j in range(3):
                if i != j and (not state[j] or state[j][-1] > disc):
                    new_state = list(list(peg) for peg in state)
                    new_state[i].pop()
                    new_state[j].append(disc)
                    successors.append(tuple(tuple(peg) for peg in new_state))
        return successors

def dfs(hanoi):
    stack = [(hanoi.initial_state, [])]
    visited = set()
    
    while stack:
        state, path = stack.pop()
        if hanoi.is_goal(state):
            return path + [state]
        if state not in visited:
            visited.add(state)
            for successor in hanoi.get_successors(state):
                stack.append((successor, path + [state]))
    return None

def bfs(hanoi):
    queue = deque([(hanoi.initial_state, [])])
    visited = set()
    
    while queue:
        state, path = queue.popleft()
        if hanoi.is_goal(state):
            return path + [state]
        if state not in visited:
            visited.add(state)
            for successor in hanoi.get_successors(state):
                queue.append((successor, path + [state]))
    return None

def dls(hanoi, limit):
    def recursive_dls(state, path, limit):
        if hanoi.is_goal(state):
            return path + [state]
        if limit <= 0:
            return None
        for successor in hanoi.get_successors(state):
            result = recursive_dls(successor, path + [state], limit - 1)
            if result:
                return result
        return None
    
    return recursive_dls(hanoi.initial_state, [], limit)

def compare_algorithms(num_discs):
    hanoi = Hanoi(num_discs)
    
    # DFS
    start_time = time.time()
    dfs_solution = dfs(hanoi)
    dfs_time = time.time() - start_time
    dfs_steps = len(dfs_solution) if dfs_solution else float('inf')
    
    # BFS
    start_time = time.time()
    bfs_solution = bfs(hanoi)
    bfs_time = time.time() - start_time
    bfs_steps = len(bfs_solution) if bfs_solution else float('inf')
    
    # DLS with limit = 2*num_discs (arbitrary choice for comparison)
    limit = 2 * num_discs
    start_time = time.time()
    dls_solution = dls(hanoi, limit)
    dls_time = time.time() - start_time
    dls_steps = len(dls_solution) if dls_solution else float('inf')
    
    print(f"Number of Discs: {num_discs}")
    print(f"DFS - Time: {dfs_time:.4f}s, Steps: {dfs_steps}")
    print(f"BFS - Time: {bfs_time:.4f}s, Steps: {bfs_steps}")
    print(f"DLS - Time: {dls_time:.4f}s, Steps: {dls_steps}")

# Execute the function with the number of discs specified
compare_algorithms(5)