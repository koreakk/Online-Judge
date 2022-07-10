#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int rotate(int** map, int x1, int y1, int x2, int y2) {

    int curr = 0;
    int prev = map[x1 + 1][y1];
    int ans = prev;
    
    for (int y = y1; y < y2; y++) {
        curr = map[x1][y];
        map[x1][y] = prev;
        prev = curr;

        ans = (ans < prev) ? ans : prev;
    }

    for (int x = x1; x < x2; x++) {
        curr = map[x][y2];
        map[x][y2] = prev;
        prev = curr;

        ans = (ans < prev) ? ans : prev;
    }

    for (int y = y2; y > y1; y--) {
        curr = map[x2][y];
        map[x2][y] = prev;
        prev = curr;

        ans = (ans < prev) ? ans : prev;
    }

    for (int x = x2; x > x1; x--) {
        curr = map[x][y1];
        map[x][y1] = prev;
        prev = curr;

        ans = (ans < prev) ? ans : prev;
    }

    return ans;
}


// queries_row_len은 2차원 배열 queries의 행(세로) 길이입니다.
// queries_col_len은 2차원 배열 queries의 열(가로) 길이입니다.
// queries[i][j]는 queries의 i번째 행의 j번째 열에 저장된 값을 의미합니다.
int* solution(int rows, int columns, int** queries, size_t queries_row_len, size_t queries_col_len) {


    int** map = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        map[i] = (int*)malloc(sizeof(int) * columns);

        for (int j = 0; j < columns; j++) {
            map[i][j] = (i * columns) + j + 1;
        }
    }

    int* answer = (int*)malloc(sizeof(int) * queries_row_len);

    for (int i = 0; i < queries_row_len; i++) {

        int x1 = queries[i][0] - 1;
        int y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3] - 1;

        // 회전
        answer[i] = rotate(map, x1, y1, x2, y2);
    }

    for (int i = 0; i < rows; i++)
        free(map[i]);
    free(map);

    return answer;
}