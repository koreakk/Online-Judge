def solution(board: list[list[int]]) -> None:
    def compare(x: int, y: int) -> bool:
        if x >= 19 or x < 0 or y >= 19 or y < 0:
            return False
        return True

    dx = (-1, 1, 1, 0)
    dy = (1, 0, 1, 1)

    def F(x: int, y: int) -> True:
        if not board[x][y]:
            return False
        
        color = board[x][y]
        for i in range(4):
            # 예외 처리
            _x = x + (dx[i] * 4)
            _y = y + (dy[i] * 4)
            if not compare(_x, _y):
                continue

            # 육목 검사
            _x += dx[i]
            _y += dy[i]
            if compare(_x, _y) and board[_x][_y] == color:
                continue
            _x = x - dx[i]
            _y = y - dy[i]
            if compare(_x, _y) and board[_x][_y] == color:
                continue
            
            # 오목 검사
            _x, _y = x, y
            for _ in range(4):
                _x += dx[i]
                _y += dy[i]
                if board[_x][_y] != color:
                    break
            else:
                return True
        return False

    for i in range(19):
        for j in range(19):
            if F(i, j):
                print(board[i][j])
                print(i + 1, j + 1)
                return
    print(0)


if __name__ == '__main__':
    board = [[0] * 19 for _ in range(19)]
    for i in range(19):
        board[i][:] = map(int, input().split())

    solution(board)