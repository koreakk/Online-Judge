#include <stdio.h>

typedef struct pos {
    int x;
    int y;
} Pos;

int BFS(int N, int M, int graph[][100])
{
    Pos queue[10000];
    int front = 0, rear = 0;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue[rear++] = (Pos){0, 0};

    while (front < rear) {
        Pos pop = queue[front++];

        for (int i = 0; i < 4; i++) {
            int x = pop.x + dx[i];
            int y = pop.y + dy[i];

            if (x < 0 || N <= x || y < 0 || M <= y) continue;
            if (graph[x][y] == 1) {
                graph[x][y] = graph[pop.x][pop.y] + 1;
                queue[rear++] = (Pos){x, y};
            }
        }
    }
    return graph[N - 1][M - 1];
}

int main(void)
{
    int N, M;
    int graph[100][100];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    printf("%d \n", BFS(N, M, graph));
    return 0;
}