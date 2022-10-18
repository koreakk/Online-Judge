#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int dp[1001][1001];

int solution(const char* x, const char* y)
{
    memset(dp, 0, sizeof(dp));

    const size_t x_len = strlen(x);
    const size_t y_len = strlen(y);

    for (size_t i = 1; i <= x_len; ++i) {
        for (size_t j = 1; j <= y_len; ++j) {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[x_len][y_len];
}

int main(void)
{
    char* x[1001], y[1001];
    scanf("%s %s", x, y);

    printf("%d\n", solution(x, y));
    return 0;
}