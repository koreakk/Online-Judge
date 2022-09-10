dp = [[0] * 101 for _ in range(101)]

def solution(n, m):
    for i in range(1, n + 1):
        for j in range(1, min(i, m) + 1):   
            dp[i][j] = (
                i if j <= 1 else \
                1 if i == j else \
                dp[i - 1][j - 1] + dp[i - 1][j]
            )
    
    return dp[n][m]

if __name__ == '__main__':
    n, m = map(int, input().split())

    print(solution(n, m))