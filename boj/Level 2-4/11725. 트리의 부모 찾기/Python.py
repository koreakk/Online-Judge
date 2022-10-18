from sys import stdin

N = int(stdin.readline())
graph = [[] for _ in range(N + 1)]

for _ in range(N - 1):
    u, v = map(int, stdin.readline().split())

    graph[u].append(v)
    graph[v].append(u)

parent_info = [-1] * (N + 1)

stack = [1]
while stack:
    parent = stack.pop()

    for child in graph[parent]:
        if parent_info[child] != -1:
            continue

        parent_info[child] = parent
        stack.append(child)

print(*parent_info[2:], sep='\n')