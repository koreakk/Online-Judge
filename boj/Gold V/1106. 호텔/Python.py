c, n = map(int, input().split())

info = []
for _ in range(n):
    cost, client = map(int, input().split())
    info.append((cost, client))

dp = [0] + [1e9] * (c + 100)

for cost, client in info:
    for i in range(client, c + 101):
        dp[i] = min(dp[i], dp[i - client] + cost)

print(min(dp[c:]))