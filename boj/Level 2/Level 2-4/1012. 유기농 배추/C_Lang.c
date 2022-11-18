#include <stdio.h>

void dfs(int i, int j, int N, int M, int graph[][50])
{
    if (0 > i || i >= N || 0 > j || j >= M) return;
    if (graph[i][j] == 0) return;

    graph[i][j] = 0;

    dfs(i + 1, j, N, M, graph);
    dfs(i - 1, j, N, M, graph);
    dfs(i, j + 1, N, M, graph);
    dfs(i, j - 1, N, M, graph);
}

int solution(int N, int M, int graph[][50])
{
    int count = 0;
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (graph[i][j] == 1) {
                dfs(i, j, N, M, graph);
                count++;
            }
        }
    }
    return count;
}

int main(void)
{
    int T;
    int N, M, K;
    int graph[50][50] = {0, };
    int i, j, x, y; 

    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%d %d %d", &N, &M, &K);
        for (j = 0; j < K; j++) {
            scanf("%d %d", &x, &y);
            graph[x][y] = 1;
        }

        printf("%d \n", solution(N, M, graph));
    }
    return 0;  
}