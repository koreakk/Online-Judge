#include <stdbool.h>

#define INT(x) ((x) - ('0'))

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int rows[9] = { 0, };
    int cols[9] = { 0, };
    int subs[9] = { 0, };

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.')
                continue;

            int x = 1 << INT(board[i][j]);

            int k = (i / 3) * 3 + (j / 3);
            if (rows[i] & x || cols[j] & x || subs[k] & x)
                return false;

            rows[i] |= x;
            cols[j] |= x;
            subs[k] |= x;
        }
    }

    return true;
}

