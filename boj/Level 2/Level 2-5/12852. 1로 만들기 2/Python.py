X = int(input())

dp   = [0] * (X + 1)
prev = [0] * (X + 1)

for i in range(1, X):
    val = dp[i] + 1
    
    for n in (i + 1, i * 2, i * 3):
        if (n <= X and (not dp[n] or dp[n] > val)):
            dp[n]   = val
            prev[n] = i

print(dp[X])
while X != 0:
    print(X, end=' ')
    X = prev[X]