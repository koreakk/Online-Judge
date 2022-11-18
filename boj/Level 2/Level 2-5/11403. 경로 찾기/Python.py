from collections import deque

N = int(input())
graph = []

for _ in range(N):
    rows = list((map(int, input().split())))
    graph.append(rows)


def bfs(start):
    queue = deque([start])
    answer = [0] * len(graph[start])

    while (queue):
        v = queue.popleft()

        for i in range(N):
            if graph[v][i] and not answer[i]:
                queue.append(i)
                answer[i] = 1

    return answer
        
for i in range(N):
    print(*bfs(i))