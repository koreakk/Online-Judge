def solution(n: int, m: int, board: list[list[int]]) -> int:
    def isOutIndex(x: int, y: int) -> bool:
        return x >= 0 and x < n and y >= 0 and y < m

    def isSquare(n: int) -> bool:
        square = n ** 0.5
        return square.is_integer()

    answer = -1
    for i in range(n):
        for j in range(m):
            for dx in range(-n, n):
                for dy in range(-m, m):
                    if dx == 0 and dy == 0:
                        continue

                    num = 0
                    x, y = i, j
                    while isOutIndex(x, y):
                        num = num * 10 + board[x][y]
                        if isSquare(num):
                            answer = max(answer, num)
                        
                        x += dx
                        y += dy

    return answer


if __name__ == '__main__':
    n, m = map(int, input().split())

    board = []
    for _ in range(n):
        board.append(list(map(int, input())))
    
    print(solution(n, m, board))
