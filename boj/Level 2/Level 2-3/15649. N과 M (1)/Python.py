def solution(n: int, m: int):
    sequence = [0] * m
    visited = [False] * (n + 1)

    def F(idx: int):
        if idx == m:
            print(*sequence)
            return
        
        for num in range(1, n + 1):
            if visited[num]:
                continue

            sequence[idx] = num
            visited[num] = True

            F(idx + 1)
            visited[num] = False
    F(0)


if __name__ == '__main__':
    n, m = map(int, input().split())
    solution(n, m)