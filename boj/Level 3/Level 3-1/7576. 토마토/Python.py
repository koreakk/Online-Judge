import sys
import collections


def BFS():
    dx = (-1, 1, 0, 0)
    dy = (0, 0, -1, 1)
    
    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or N <= nx or ny < 0 or M <= ny: continue

            if graph[nx][ny] == 0:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))
                

if __name__ == '__main__':
    M, N = map(int, input().split())
    graph = []
    queue = collections.deque()

    for _ in range(N):
        graph.append(list(map(int, sys.stdin.readline().rstrip().split())))

    for x in range(N):
        for y in range(M):
            if graph[x][y] == 1:
                queue.append((x, y))
    
    BFS()

    result = 1
    iszero = False

    for i in range(N):
        for j in range(M):
            if graph[i][j] > result:
                result = graph[i][j]
            elif graph[i][j] == 0:
                iszero = True

    print(-1 if iszero else result - 1)