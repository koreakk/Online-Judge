#include <stdio.h>

int dp[101][101][101];

int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    else if (dp[a+50][b+50][c+50])
        return dp[a+50][b+50][c+50];

    else if (a > 20 || b > 20 || c > 20)
        dp[a+50][b+50][c+50] =  w(20, 20, 20);

    else if (a < b && b < c)
        dp[a+50][b+50][c+50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

    else
        dp[a+50][b+50][c+50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    
    return dp[a+50][b+50][c+50];
}

int main(void) {
    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;

        printf("w(%d, %d, %d) = %d \n", a, b, c, w(a, b, c));
    }
    return 0;
}