from collections import deque

def DFS(v):
    dfs_visited[v] = False
    print(v, end=' ')

    for i in sorted(graph[v]):
        if dfs_visited[i]:
            DFS(i)

def BFS(start):
    queue = deque([start])
    bfs_visited[start] = False

    while queue:
        p = queue.popleft()
        print(p, end=' ')

        for i in sorted(graph[p]):
            if bfs_visited[i]:
                queue.append(i)
                bfs_visited[i] = False

if __name__ == '__main__':
    n, m, v = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    dfs_visited = [True] * (n + 1)
    bfs_visited = [True] * (n + 1)

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    DFS(v); print()
    BFS(v)
