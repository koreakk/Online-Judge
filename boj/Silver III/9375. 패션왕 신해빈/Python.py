from collections import defaultdict

T = int(input())
for _ in range(T):
    n = int(input())
    if n == 0:
        print(0)
        continue

    info = defaultdict(int)
    for _ in range(n):
        _, dtype = input().split()
        info[dtype] += 1

    answer = 1
    for c in info.values():
        answer *= c + 1
    answer -= 1

    print(answer)