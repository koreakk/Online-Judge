def solution(points: tuple[tuple[int, int]]) -> int:
    graph = [[0] * 101 for _ in range(101)]

    for x, y in points:
        for i in range(x, x + 10):
            for j in range(y, y + 10):
                graph[i][j] = 1
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def F(x: int, y: int) -> int:
        if not graph[x][y]:
            return 0
        
        answer = 0
        for i in range(4):
            if not graph[x + dx[i]][y + dy[i]]:
                answer += 1
        return answer

    return sum(F(x, y) for x in range(100) for y in range(100))


if __name__ == '__main__':
    n = int(input())
    points = list()

    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))
    
    print(solution(points))
