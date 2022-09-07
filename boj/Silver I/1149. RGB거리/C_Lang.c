#include <stdio.h>

int map[1000][3], N;
int dp[1000][3];

int min(int left, int right)
{
    return left < right ? left : right;
}

int solution()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int color = 0; color < 3; ++color)
        {
            dp[i][color] = min(
                dp[i - 1][(color + 1) % 3],
                dp[i - 1][(color + 2) % 3]
            ) + map[i - 1][color];
        }
    }

    int result = (int)1e9;
    for (int color = 0; color < 3; ++color)
    {
        result = min(result, dp[N][color]);
    }

    return result;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            scanf("%d", map[i] + j);
        }
    }

    printf("%d\n", solution());
    return 0;
}