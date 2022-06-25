#include <stdio.h>
#include <stdbool.h>


typedef struct pos {
    int x;
    int y;
    bool b;
} Pos;


int BFS(int N, int M, int map[][1000][2])
{
    Pos queue[2000000];
    int front = 0, rear = 0;
    int A, B;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    map[0][0][0] = 1;
    map[0][0][1] = 1;
    queue[rear++] = (Pos){0, 0, false};

    while (front < rear) {
        Pos pop = queue[front++];

        for (int i = 0; i < 4; i++) {
            int x = pop.x + dx[i];
            int y = pop.y + dy[i];
            bool b = pop.b;
            bool _b = b;

            if (x < 0 || N <= x || y < 0 || M <= y) continue;

            if (b && map[x][y][1] >= 1) continue;
            else if (map[x][y][0] == 1) b = true;

            if (map[x][y][b] <= 1) {
                map[x][y][b] = map[pop.x][pop.y][_b] + 1;
                queue[rear++] = (Pos){x, y, b};
            }

        }
    }
    A = map[N - 1][M - 1][0];
    B = map[N - 1][M - 1][1];

    if (!(A || B)) return -1;
    else if (!A) return B;
    else if (!B) return A;
    return (A < B) ? A : B;
}

int main(void)
{
    int N, M;
    int map[1000][1000][2];
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &map[i][j][0]);
            map[i][j][1] = map[i][j][0];
        }
    }

    printf("%d \n", BFS(N, M, map));
    return 0;
}