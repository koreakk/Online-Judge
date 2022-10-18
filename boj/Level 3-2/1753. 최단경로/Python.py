import heapq
from sys import stdin

INF = 1e9

N, M = map(int, stdin.readline().split())
K    = int(stdin.readline())

graph = [[] for _ in range(N + 1)]

def dijkstra(graph, source):
    dist = [INF] * (N + 1)
    dist[source] = 0

    hq = []
    heapq.heappush(hq, (0, source))
    while hq:
        weight, vertex = heapq.heappop(hq)

        for v, w in graph[vertex]:
            distance = w + weight
            if distance >= dist[v]:
                continue

            dist[v] = distance
            heapq.heappush(hq, (distance, v))

    return dist

for i in range(M):
    src, dest, weight = map(int, stdin.readline().split())
    graph[src].append((dest, weight))

dist = dijkstra(graph, K)
for i in range(1, N + 1):
    print('INF' if dist[i] == INF else dist[i])
