N = int(input())
N_list = list(map(int, input().split()))
M = int(input())
M_list = list(map(int, input().split()))

dic = {}
for i in range(N):
    if N_list[i] in dic:
        dic[N_list[i]] += 1
    else:
        dic[N_list[i]] = 1

print(*list(dic[M_list[i]] if M_list[i] in dic else 0 for i in range(M)))