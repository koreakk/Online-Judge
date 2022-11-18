#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define CHAR(n)   ((n) + '0');

void printInteger(__uint128_t n)
{
    char str[41] = { 0 };
    int top = 40;

    do
    {
        str[--top] = CHAR(n % 10);
    } while (n /= 10);

    printf("%s\n", str + top);
}

__uint128_t dp[101][101];

__uint128_t solution(int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1, length = min(i, m); j <= length; ++j)
        {
            dp[i][j] = (
                (j <= 1) ? i : \
                (i == j) ? 1 : \
                dp[i - 1][j - 1] + dp[i - 1][j]
            );
        }

    }

    return dp[n][m];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    printInteger(solution(n, m));
    return 0;
}