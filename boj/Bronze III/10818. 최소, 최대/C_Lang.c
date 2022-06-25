#include <stdio.h>

int main(void)
{
    int i, n, input;
    int min = 1000000, max = -1000000;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &input);
        min = (min < input) ? min : input;
        max = (max > input) ? max : input;
    }
    printf("%d %d", min, max);
    return 0;
}