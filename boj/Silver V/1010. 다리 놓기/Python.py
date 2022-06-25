def solution(n: int, m: int) -> int:
    dp = [[0] * (m + 1) for _ in range(n + 1)]

    def F(n: int, m: int) -> int:
        if n <= 1: return m
        if n == m: return 1

        if not dp[n][m]:
            dp[n][m] = F(n - 1, m - 1) + F(n, m - 1)

        return dp[n][m]

    return F(n, m)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        print(solution(n, m))