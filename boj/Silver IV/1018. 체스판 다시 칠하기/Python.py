def solution(n: int, m: int, board: list[str]) -> int:
    def F(x: int, y: int) -> int:
        check = 'BW', 'WB'
        
        diff = 0
        for i in range(x, x + 8):
            for j in range(y, y + 8, 2):
                curr = board[i][j: j + 2]
                
                if check[i % 2 == 0] != curr:
                    diff += 2 if curr in check else 1
        return min(64 - diff, diff)
    
    answer = 64
    for i in range(n - 7):
        for j in range(m - 7):
            answer = min(answer, F(i, j))
    return answer


if __name__ == '__main__':
    n, m = map(int, input().split())

    board = list()
    for i in range(n):
        board.append(input())
    
    print(solution(n, m, board))
