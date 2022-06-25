#include <stdio.h>

int main(void)
{
    int n;
    int i, j;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = n-i; j > 0; j--)
            printf(" ");
            
        for (j = 1; j < i*2; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}