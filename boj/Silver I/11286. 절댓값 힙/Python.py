from sys import stdin
import heapq

N = int(stdin.readline())
heap = []

for _ in range(N):
    x = int(stdin.readline())

    if x == 0 and heap:
        print(heapq.heappop(heap)[1])
    elif x == 0:
        print(0)
    else:
        heapq.heappush(heap, (abs(x), x))