#include <stdio.h>

int MAX(int x, int y)
{
    return x > y ? x : y;
}

int dp[2][100000];

int solution(int n)
{
    for (int i = 1; i < n; ++i) {
        dp[0][i] = MAX(dp[0][i - 1], dp[0][i] + dp[1][i - 1]);
        dp[1][i] = MAX(dp[1][i - 1], dp[1][i] + dp[0][i - 1]);
    }

    return MAX(dp[0][n - 1], dp[1][n - 1]);
}

int main(void)
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", dp[i] + j);
            }
        }

        printf("%d\n", solution(n));
    }

    return 0;
}