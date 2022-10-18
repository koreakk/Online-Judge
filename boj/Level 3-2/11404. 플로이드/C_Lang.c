#include <stdio.h>

const int INF = 100000000;

int graph[100][100];
int dp[100][100];

int min(int a, int b)
{
    return a < b ? a : b;
}

void solution(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = i == j      ? 0 :
                       graph[i][j] ? graph[i][j] :
                                     INF;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int src, dest, cost;
        scanf("%d %d %d", &src, &dest, &cost);

        int* position = graph[src - 1] + dest - 1;
        if (*position == 0 || *position > cost) {
            *position = cost;
        }
    }

    solution(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", dp[i][j] != INF ? dp[i][j] : 0);
        }
        printf("\n");
    }

    return 0;
}