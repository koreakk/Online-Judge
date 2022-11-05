#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool isOutIndex(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool isSquare(int n) {
    if (n == 0 || n == 1)
        return true;

    long long start = 1, end = (long long)n;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        long long target = mid * mid;

        if (target == n)
            return true;

        if (target < n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}

int solution(int n, int m, int** board) {
    int answer = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dx = -n; dx < n; dx++) {
                for (int dy = -m; dy < m; dy++) {
                    if (dx == 0 && dy == 0)
                        continue;

                    int num = 0;
                    int x = i, y = j;
                    while (isOutIndex(x, y, n, m)) {
                        num = num * 10 + board[x][y];
                        if (isSquare(num) && answer < num)
                            answer = num;

                        x += dx;
                        y += dy;
                    }
                }
            }
        }
    }
    return answer;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int** board = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        board[i] = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++) {
            scanf("%1d", board[i] + j);
        }
    }

    printf("%d\n", solution(n, m, board));

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);

    return 0;
}