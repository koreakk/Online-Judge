#include <stdio.h>
#include <stdlib.h>

long long solution(int n, int* distances, int* prices)
{
    long long result = 0;
    int price = 1000000000;
    int i;
    for (i = 0; i < n - 1; i++) {
        price = (price < prices[i]) ? price : prices[i];
        result += (long long)price * (long long)distances[i];
    }
    return result;
}

int main(void)
{
    int i, n;
    scanf("%d", &n);

    int *distances = (int*)malloc(sizeof(int) * (n - 1));
    for (i = 0; i < n - 1; i++) {
        scanf("%d", distances + i);
    }

    int *prices = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", prices + i);
    }

    printf("%lld", solution(n, distances, prices));
    free(distances);
    free(prices);
    return 0;
}