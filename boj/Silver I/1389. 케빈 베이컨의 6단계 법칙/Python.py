from collections import deque

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(x):
    queue = deque([x])
    relations = [0] * (n + 1)

    while queue:
        q = queue.popleft()

        for i in graph[q]:
            if relations[i] == 0:
                relations[i] = relations[q] + 1
                queue.append(i)

    return sum(relations)

print(min(range(1, n + 1), key=bfs))