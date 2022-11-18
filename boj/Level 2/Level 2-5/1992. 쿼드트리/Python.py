n = int(input())
board = []
for _ in range(n):
    board.append(list(input()))

def solution(size: int, x: int, y: int) -> str:
    if size <= 1:
        return board[x][y]
    
    s = size // 2
    A = solution(s, x, y)
    B = solution(s, x, y + s)
    C = solution(s, x + s, y)
    D = solution(s, x + s, y + s)

    if len(A) == 1 and A == B == C == D:
        return A
    return f'({A}{B}{C}{D})'

print(solution(n, 0, 0))