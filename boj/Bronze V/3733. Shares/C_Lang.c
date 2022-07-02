#include <stdio.h>

int main(void) {
    int n, s;
    while (scanf("%d %d", &n, &s) != EOF)
        printf("%d\n", s / (n + 1));
    
    return 0;
}