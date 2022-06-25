#include <stdio.h>

typedef struct point {
    int x;
    int y;
} Point;

int BFS(int N, Point start, Point end)
{
    if (start.x == end.x && start.y == end.y)
        return 0;

    int map[300][300] = {0, };
    Point queue[100000];
    int front = 0, rear = 0;
    int dx[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    int dy[8] = {2, 2, -2, -2, 1, 1, -1, -1};

    queue[rear++] = start;
    while (front < rear) {
        Point pop = queue[front++];

        for (int i = 0; i < 8; i++) {
            int x = pop.x + dx[i];
            int y = pop.y + dy[i];

            if (x < 0 || N <= x || y < 0 || N <= y) continue;

            if (map[x][y] == 0) {
                map[x][y] = map[pop.x][pop.y] + 1;
                queue[rear++] = (Point){x, y};
            }
            if (end.x == x && end.y == y) return map[x][y];
        }
    }
    return 0;
}

int main(void)
{
    int T, N;
    Point start, end;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &N);
        scanf("%d %d", &start.x, &start.y);
        scanf("%d %d", &end.x, &end.y);
        printf("%d \n", BFS(N, start, end));
    }
    return 0;
}