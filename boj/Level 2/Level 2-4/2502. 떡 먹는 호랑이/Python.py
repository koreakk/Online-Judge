def solution(d: int, k: int) -> tuple[int, int]:
    dp = [0] * d
    def F(n: int) -> int:
        if n <= 2:
            return 1

        if not dp[n]:
            dp[n] = F(n - 1) + F(n - 2)
        return dp[n]

    A, B = F(d - 2), F(d - 1)

    for x in range(1, k):
        y = (k - A*x) // B

        if A*x + B*y == k:
            return (x, y)


if __name__ == '__main__':
    d, k = map(int, input().split())
    print(*solution(d, k), sep='\n')