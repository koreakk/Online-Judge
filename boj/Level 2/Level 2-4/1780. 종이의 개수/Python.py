from sys import stdin

n = int(stdin.readline())
board = []
for _ in range(n):
    board.append(list(map(int, stdin.readline().split())))

def merge(l1: list, l2: list):
    return [i + j for i, j in zip(l1, l2)]


def solution(size: int, x: int, y: int):
    answer = [0, 0, 0]
    
    if size <= 1:
        answer[board[x][y] + 1] = 1
        return answer

    s = size // 3
    for dx in range(0, size, s):
        for dy in range(0, size, s):
            answer = merge(
                answer,
                solution(s, x + dx, y + dy)
            )
    
    if answer.count(0) >= 2:
        return [1 if i else 0 for i in answer]
    return answer

print(*solution(n, 0, 0), sep='\n')