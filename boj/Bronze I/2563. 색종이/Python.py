def solution(n: int, points: tuple[tuple[int, int]]) -> int:
    graph = [[0] * 100 for _ in range(100)]

    for i in range(n):
        x, y = points[i]

        for j in range(x, x + 10):
            for k in range(y, y + 10):
                graph[j][k] = 1
    
    answer = 0
    for row in graph:
        answer += sum(row)
    
    return answer


if __name__ == '__main__':
    n = int(input())
    points = list()

    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    
    print(solution(n, points))
