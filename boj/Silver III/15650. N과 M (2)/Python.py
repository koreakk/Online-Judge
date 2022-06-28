def solution(n: int, m: int):
    sequence = [0] * m

    def F(idx: int, start: int):
        if idx == m:
            print(*sequence)
            return
        
        for num in range(start, n + 1):
            sequence[idx] = num
            F(idx + 1, num + 1)
    F(0, 1)


if __name__ == '__main__':
    n, m = map(int, input().split())
    solution(n, m)