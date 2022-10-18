import heapq

INF = 1e9

N, M, X = map(int, input().split())
graph         = [[] for _ in range(N + 1)]
reverse_graph = [[] for _ in range(N + 1)]

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
    src, dest, weight = map(int, input().split())
    graph[src].append((dest, weight))
    reverse_graph[dest].append((src, weight))

dist         = dijkstra(graph, X)
reverse_dist = dijkstra(reverse_graph, X)

result = max(dist[i] + reverse_dist[i] for i in range(1, N + 1))
print(result)
    