#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = matrixSize - 1, j = 0;

    while (i >= 0 && j < matrixColSize[i]) {
        if (matrix[i][j] == target)
            return true;
        
        if (matrix[i][j] > target)
            i--;
        else
            j++;
    }

    return false;
}