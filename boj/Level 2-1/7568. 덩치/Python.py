def solution(n: int, data: list[tuple[int, int]]) -> list[int]:
    answer = [1] * n
    for i in range(n):
        x, y = data[i]
        for j in range(i + 1, n):
            p, q = data[j]

            if x > p and y > q:
                answer[j] += 1
            elif x < p and y < q:
                answer[i] += 1
    
    return answer


if __name__ == '__main__':
    n = int(input())
    data = list()
    for _ in range(n):
        x, y = map(int, input().split())
        data.append((x, y))
    
    print(*solution(n, data))