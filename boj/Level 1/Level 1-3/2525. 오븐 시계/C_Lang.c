#include <stdio.h>

int main(void)
{
    int A, B, C;
    
    scanf("%d %d", &A, &B);
    scanf("%d", &C);
    
    printf("%d %d", (A + (B + C) / 60) % 24, (B + C) % 60);
    return 0;
}