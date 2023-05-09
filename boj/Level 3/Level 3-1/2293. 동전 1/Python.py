n, k = map(int, input().split())

dp    = [0] * (k+1)
dp[0] = 1

for _ in range(n):
    c = int(input())

    for i in range(c, k+1):
        dp[i] += dp[i-c]

print(dp[k])
