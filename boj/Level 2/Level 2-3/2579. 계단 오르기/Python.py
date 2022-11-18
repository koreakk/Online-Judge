n = int(input())
info = []
for _ in range(n):
    info.append(int(input()))

dp = [0] * (n)
def F(x, c):
    if x < 0: return 0
    if c:
        return F(x - 2, 0) + info[x]

    if not dp[x]:
        dp[x] = max(
            F(x - 2, 0),
            F(x - 1, c + 1)
        ) + info[x]

    return dp[x]
    
print(F(n - 1, 0))
