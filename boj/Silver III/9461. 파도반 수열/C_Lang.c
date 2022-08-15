#include <stdio.h>

long long solution(int n)
{
    long long dp[101] = { 1, 1, 1 };

    for (int i = 3; i < n; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    return dp[n - 1];
}

int main(void)
{
    int T;
    int n;

    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        printf("%lld\n", solution(n));
    }
}