#include <stdio.h>

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
    int distances[n - 1];
    int prices[n];
    for (i = 0; i < n - 1; i++) {
        scanf("%d", distances + i);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", prices + i);
    }
    printf("%lld", solution(n, distances, prices));
    return 0;
}