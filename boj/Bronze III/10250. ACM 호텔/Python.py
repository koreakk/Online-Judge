T = int(input())
for _ in range(T):
    H, W, N = map(int, input().split())

    answer = ((N-1) % H + 1) * 100 + ((N-1) // H + 1)
    print(answer)