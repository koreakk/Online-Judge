#include <stdio.h>

int main(void)
{
    int A = 0, I = 0;

    scanf("%d %d", &A, &I);
    printf("%d\n", A * (I - 1) + 1);

    return 0;
}