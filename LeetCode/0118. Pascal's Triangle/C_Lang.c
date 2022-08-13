#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** answer = (int**)malloc(sizeof(int*) * numRows);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        answer[i] = (int*)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                answer[i][j] = 1;
            else
                answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
        }
    }

    return answer;
}