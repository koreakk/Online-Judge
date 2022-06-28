def solution(n: int, m: int):
    sequence = [0] * m

    def F(idx: int):
        if idx == m:
            print(*sequence)
            return

        for num in range(1, n + 1):
            sequence[idx] = num
            F(idx + 1)
    F(0)


if __name__ == '__main__':
    n, m = map(int, input().split())
    solution(n, m)