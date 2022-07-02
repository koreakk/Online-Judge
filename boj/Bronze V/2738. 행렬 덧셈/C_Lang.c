#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int** A = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        A[i] = (int*)malloc(sizeof(int) * m);
        
        for (int j = 0; j < m; j++)
            scanf("%d", A[i] + j);
    }

    int** B = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        B[i] = (int*)malloc(sizeof(int) * m);
        
        for (int j = 0; j < m; j++)
            scanf("%d", B[i] + j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", A[i][j] + B[i][j]);
        putchar('\n');
    }

    for (int i = 0; i < n; i++) {
        free(A[i]), free(B[i]);
    }
    free(A), free(B);
    return 0;
}