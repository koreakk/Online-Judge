#include <stdio.h>

int main(void)
{
    int i, N, K;
    int arr[10];
    int result = 0;
    
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) {
        scanf("%d", arr + i);
    }

    for (i = N - 1; i >= 0; i--) {
        result += K / arr[i];
        K %= arr[i];
    }

    printf("%d \n", result);
    return 0;
}