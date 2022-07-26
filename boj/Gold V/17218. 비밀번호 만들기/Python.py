word_A = input()
word_B = input()

A_len, B_len = len(word_A), len(word_B)
dp = [[0] * (A_len + 1) for _ in range(B_len + 1)]

# LCS 문제
for i in range(1, B_len + 1):
    for j in range(1, A_len + 1):
        if word_B[i - 1] == word_A[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

result = ''
y, x = B_len, A_len
while dp[y][x]:
    if dp[y][x] == dp[y][x - 1]:
        x -= 1
    elif dp[y][x] == dp[y - 1][x]:
        y -= 1
    else:
        y, x = y - 1, x - 1
        result = word_A[x] + result

print(result)