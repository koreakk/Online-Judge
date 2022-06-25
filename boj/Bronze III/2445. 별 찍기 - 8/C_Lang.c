#include <stdio.h>

int main(void)
{
    int n;
    int i, j;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 0; j < i; j++)
            printf("*");
        
        for (j = i; j < n*2-i; j++)
            printf(" ");
        
        for (j = 0; j < i; j++)
            printf("*");
        printf("\n");  
    }

    for (i = 1; i <= n; i++) {
        for (j = n-i; j > 0; j--)
            printf("*");
        
        for (j = 0; j < i*2; j++)
            printf(" ");
        
        for (j = n-i; j > 0; j--)
            printf("*");
        printf("\n");  
    }
    return 0;
}