from sys import stdin
from collections import deque

n, m = map(int, stdin.readline().split())
graph = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(m):
    u, v = map(int, stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

def bfs(x):
    queue = deque([x])
    visited[x] = True

    while queue:
        v = queue.popleft()

        for u in graph[v]:
            if visited[u]:
                continue
            
            visited[u] = True
            queue.append(u)
        
answer = 0
for v in range(1, n + 1):
    if visited[v]:
        continue
    answer += 1
    bfs(v)

print(answer)
        