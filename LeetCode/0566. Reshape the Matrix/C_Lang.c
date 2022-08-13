#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = *matColSize;
    if (r *c != m * n) {
        r = m;
        c = n;
    }

    *returnSize = r;
    int** answer = (int**)malloc(sizeof(int*) * r);
    *returnColumnSizes = (int*)malloc(sizeof(int) * r);

    for (int i = 0; i < r; i++) {
        answer[i] = (int*)malloc(sizeof(int) * c);
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < r * c; i++)
        answer[i/c][i%c] = mat[i/n][i%n];
    
    return answer;
}
