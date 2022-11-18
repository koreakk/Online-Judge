#include <stdio.h>

int main(void)
{
    int n1, n2, n3;
    int result;
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 == n2 && n1 == n3) {
        result = 10000 + n1 * 1000;
    } 
    else if (n1 == n2 || n1 == n3 || n2 == n3) {
        result = 1000 + ((n1 == n2) ? n1 : n3) * 100;
    }
    else {
        if (n1 > n2)
            result = ((n1 > n3) ? n1 : n3) * 100;
        else
            result = ((n2 > n3) ? n2 : n3) * 100;
    }
    printf("%d \n", result);
    return 0;       
}