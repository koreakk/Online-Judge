def solution(board, skill):
    board_rows = len(board)
    board_cols = len(board[0])

    temp = [[0] * (board_cols + 1) for _ in range(board_rows + 1)]

    for type, r1, c1, r2, c2, degree in skill:
        if type == 1:
            degree = -degree
        
        temp[r1][c1]         += degree
        temp[r1][c2 + 1]     -= degree
        temp[r2 + 1][c1]     -= degree
        temp[r2 + 1][c2 + 1] += degree 


    # 누적합 계산
    for row in range(board_rows):
        for col in range(1, board_cols):
            temp[row][col] += temp[row][col - 1]

    for col in range(board_cols):
        for row in range(1, board_rows):
            temp[row][col] += temp[row - 1][col]

    
    answer = 0
    for row in range(board_rows):
        for col in range(board_cols):
            if board[row][col] + temp[row][col] >= 1:
                answer += 1

    return answer