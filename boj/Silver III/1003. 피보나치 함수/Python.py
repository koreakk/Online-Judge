def solution(n: int):
    if n == 0:
        return (1, 0)
    if n == 1:
        return (0, 1)

    dp = [0] * n
    def F(n: int) -> list[int]:
        if n <= 1:
            return 1

        if not dp[n]:
            dp[n] = F(n - 1) + F(n - 2)
        return dp[n]

    return (F(n - 2), F(n - 1))


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        n = int(input())
        print(*solution(n))