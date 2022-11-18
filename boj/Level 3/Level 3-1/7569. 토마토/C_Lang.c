#include <stdio.h>


typedef struct pos {
    int x;
    int y;
    int z;
} Pos;

void BFS(int M, int N, int H, int qsize, Pos queue[], int graph[][100][100]);

int solution(int M, int N, int H, int graph[][100][100])
{
    Pos queue[1000000];
    int rear = 0;
    int result = 0;
    int x, y, z;
    for (z = 0 ; z < H; z++) {
        for (x = 0; x < N; x++) {
            for (y = 0; y < M; y++)
                if (graph[z][x][y] == 1) {
                    queue[rear++] = (Pos){x, y, z};
                }
        }
    }

    BFS(M, N, H, rear, queue, graph);
    
    for (z = 0; z < H; z++) {
        for (x = 0; x < N; x++) {
            for (y = 0; y < M; y++) {
                if (graph[z][x][y] == 0) return -1;
                result = (result > graph[z][x][y]) ? result : graph[z][x][y];
            }
        }
    }
    return result - 1;
}

int main(void)
{
    int M, N, H;
    int graph[100][100][100];

    scanf("%d %d %d", &M, &N, &H);
    for (int z = 0 ; z < H; z++) {
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++)
            scanf("%d", &graph[z][x][y]);
        }
    }

    printf("%d", solution(M, N, H, graph));
    return 0;
}

void BFS(int M, int N, int H, int qsize, Pos queue[], int graph[][100][100])
{
    int front = 0, rear = qsize;
    int dx[6] = {0, 0, -1, 1, 0, 0};
    int dy[6] = {0, 0, 0, 0, -1, 1};
    int dz[6] = {-1, 1, 0, 0, 0, 0};

    while (front < rear) {
        Pos pop = queue[front++];

        for (int i = 0; i < 6; i++) {
            int x = pop.x + dx[i];
            int y = pop.y + dy[i];
            int z = pop.z + dz[i];

            if (x < 0 || N <= x || y < 0 || M <= y || z < 0 || H <= z) continue;

            if (graph[z][x][y] == 0) {
                graph[z][x][y] = graph[pop.z][pop.x][pop.y] + 1;
                queue[rear++] = (Pos){x, y, z};
            }
        }
    }
}