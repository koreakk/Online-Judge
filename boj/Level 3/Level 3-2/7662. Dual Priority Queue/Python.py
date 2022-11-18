from sys import stdin
from collections import defaultdict
import heapq


def push(n: int):
    table[n] += 1
    heapq.heappush(minQ, n)
    heapq.heappush(maxQ, -n)


def pop(n: int):
    if n == -1:
        while minQ:
            i = heapq.heappop(minQ)
            if table[i]:
                table[i] -= 1
                return  
    else:
        while maxQ:
            i = -heapq.heappop(maxQ)
            if table[i]:
                table[i] -= 1
                return
    

T = int(stdin.readline())
for _ in range(T):
    minQ, maxQ = [], []
    table = defaultdict(int)

    k = int(stdin.readline())
    for _ in range(k):
        s, n = stdin.readline().split()
        n = int(n)

        if s == 'I':
            push(n)
        else:
            pop(n)
    
    while maxQ and not table[-maxQ[0]]: heapq.heappop(maxQ)
    while minQ and not table[minQ[0]]: heapq.heappop(minQ)

    if not maxQ:
        print('EMPTY')
    else:
        print(-maxQ[0], minQ[0])
