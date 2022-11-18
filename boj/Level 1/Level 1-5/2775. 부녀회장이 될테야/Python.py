def solution(k: int, n: int) -> int:
    dp = [[0] * (n + 1) for _ in range(k + 1)]

    def F(k: int, n: int) -> int:
        if k == 0 or n == 1:
            return n
        
        if not dp[k][n]:
            dp[k][n] = F(k - 1, n) + F(k, n - 1)

        return dp[k][n]

    return F(k, n)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        k = int(input())
        n = int(input())

        print(solution(k, n))