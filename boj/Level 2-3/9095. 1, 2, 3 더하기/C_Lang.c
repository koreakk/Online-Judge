#include <stdio.h>

int F(int n, int dp[12])
{
    if (n < 0) return 0;
    if (n <= 1) return 1;

    if (dp[n]) return dp[n];
    dp[n] = F(n - 1, dp) + F(n - 2, dp) + F(n - 3, dp);
    return dp[n];
}

int main(void)
{
    int T, n;
    int dp[12] = {0};
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        printf("%d \n", F(n, dp));
    }
    return 0;
}