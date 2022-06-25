#include <stdio.h>


void solution(int A, int N, int M, int D, int S1, int S2)
{
    // D : 0 = left, 1 = right
    if (S1 == 1) {
        if ((D == 1 && (S2 < A)) || (D == 0 && (S2 > A))) {
            printf("YES! \n");
            return;
        }
    }
    if (S1 == N && (N - D) % 2 != 0) {
        printf("YES! \n");
        return;
    }
    printf("NO... \n");
}


int main(void)
{
    int N, M, A, D, S1, S2;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &A, &D);
    scanf("%d %d", &S1, &S2);

    solution(A, N, M, D, S1, S2);
    return 0;
}