import collections
from typing import List

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = collections.defaultdict(list)
        for u, v, w in flights:
            graph[u].append((v, w))
        
        Q = collections.deque([(0, src, k)])
        dist = [float('inf')] * n
        
        while Q:
            price, node, k = Q.popleft()
            if k >= -1 and dist[node] > price:
                dist[node] = price
                for v, w in graph[node]:
                    Q.append((price + w, v, k - 1))
            
        return dist[dst] if dist[dst] != float('inf') else -1

if __name__ == '__main__':
    n = 5
    flights = [[0,1,5],[1,2,5],[0,3,2],[3,1,2],[1,4,1],[4,2,1]]
    src = 0
    dst = 2
    k = 2        
    print(Solution().findCheapestPrice(n, flights, src, dst, k))






