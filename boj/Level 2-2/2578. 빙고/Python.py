def solution(board: list[list[int]], targets: list[list[int]]) -> int:
    def F(target: int) -> bool:
        for i in range(5):
            for j in range(5):
                if board[i][j] == target:
                    board[i][j] = 0

        # check bingo
        check_bingo = list(map(sum, board)).count(0)        # 가로
        check_bingo += list(map(sum, zip(*board))).count(0) # 세로
        check_bingo += not any([board[i][i] for i in range(5)]) # 대각선
        check_bingo += not any([board[i][j] for i, j in enumerate(range(4, -1, -1))])

        return check_bingo >= 3

    for i in range(5):
        for j in range(5):
            if F(targets[i][j]):
                return i * 5 + (j+1)

            
if __name__ == '__main__':
    board = [list(map(int, input().split())) for _ in range(5)]
    targets = [list(map(int, input().split())) for _ in range(5)]

    print(solution(board, targets))
