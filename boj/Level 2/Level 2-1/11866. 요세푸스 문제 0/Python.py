from collections import deque

N, K = map(int, input().split())
N_list = deque(list(range(1, N+1)))

result = []
while N_list:
    for _ in range(K-1):
        N_list.append(N_list.popleft())
    
    result.append(N_list.popleft())
        
print('<' + ', '.join(map(str, result)) + '>')