#include <stdio.h>


typedef struct pos {
    int x;
    int y;
} Pos;

void BFS(int M, int N, int qsize, Pos queue[], int graph[][1000]);

int solution(int M, int N, int graph[][1000])
{
    Pos queue[1000000];
    int rear = 0;
    int result = 0;
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (graph[i][j] == 1) {
                queue[rear++] = (Pos){i, j};
            }
        }
    }

    BFS(M, N, rear, queue, graph);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (graph[i][j] == 0) return -1;
            result = (result > graph[i][j]) ? result : graph[i][j];
        }
    }
    return result - 1;
}

int main(void)
{
    int M, N;
    int graph[1000][1000];

    scanf("%d %d", &M, &N);
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("%d", solution(M, N, graph));
    return 0;
}

void BFS(int M, int N, int qsize, Pos queue[], int graph[][1000])
{
    int front = 0, rear = qsize;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (front < rear) {
        Pos pop = queue[front++];

        for (int i = 0; i < 4; i++) {
            int x = pop.x + dx[i];
            int y = pop.y + dy[i];

            if (x < 0 || N <= x || y < 0 || M <= y) continue;

            if (graph[x][y] == 0) {
                graph[x][y] = graph[pop.x][pop.y] + 1;
                queue[rear++] = (Pos){x, y};
            }
        }
    }
}