#include <stdio.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
// aloc_len은 배열 aloc의 길이입니다.
// bloc_len은 배열 bloc의 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols, int aloc[], size_t aloc_len, int bloc[], size_t bloc_len) {

    static const int dx[4] = { 1, -1, 0, 0 };
    static const int dy[4] = { 0, 0, 1, -1 };

    int x = aloc[0];
    int y = aloc[1];

    if (board[x][y] == 0)
        return 0;

    int answer = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 예외 처리
        if (nx >= board_rows || nx < 0 || ny >= board_cols || ny < 0)
            continue;

        if (board[nx][ny] == 0)
            continue;

        board[x][y] = 0;

        int curr[2] = { nx, ny };
        int val = solution(board, board_rows, board_cols, bloc, bloc_len, curr, aloc_len) + 1;

        board[x][y] = 1;

        if (answer % 2 == 0 && val % 2 == 1)
            answer = val;

        else if (answer % 2 == 1 && val % 2 == 1)
            answer = (answer < val) ? answer : val;

        else if (answer % 2 == 0 && val % 2 == 0)
            answer = (answer > val) ? answer : val;
    }

    return answer;
}