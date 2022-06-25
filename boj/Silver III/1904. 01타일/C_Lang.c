#include <stdio.h>

int main(void)
{
    int x = 1, y = 2;
    int temp, n;
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        temp = y;
        y = (x + y) % 15746;
        x = temp;
    }
    printf("%d \n", x);
    return 0;
}