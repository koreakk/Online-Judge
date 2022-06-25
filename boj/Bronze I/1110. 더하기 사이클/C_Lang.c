#include <stdio.h>

int main(void)
{
    int n;
    int copy, len;

    scanf("%d", &n);
    copy = n;
    len = 0;

    do {
        n = n%10 * 10 + ((n/10 + n%10) % 10);
        len++;
    } while (n != copy);

    printf("%d", len);
    return 0;   
}