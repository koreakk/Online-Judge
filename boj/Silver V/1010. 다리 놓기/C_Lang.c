#include <stdio.h>

int dp[35][35];

int solution(size_t n, size_t m) {
    if (n <= 1) return m;
    if (n == m) return 1;

    if (!dp[n][m])
        dp[n][m] = solution(n - 1, m - 1) + solution(n, m - 1);
    return dp[n][m];
}

int main(void) {
    int T;
    int n, m;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", solution(n, m));
    }

    return 0;
}