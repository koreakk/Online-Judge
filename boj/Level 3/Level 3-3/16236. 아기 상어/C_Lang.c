#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N_MAX       20

typedef struct _POS {
    int x;
    int y;
} POS;

int map[N_MAX][N_MAX];
int N;

POS queue[10000];
int visited[N_MAX][N_MAX];

int bfs(const int x, const int y)
{
    const int dx[] = { 0, 0, 1, -1 };
    const int dy[] = { 1, -1, 0, 0 };

    int answer = 0;
    int size   = 2;
    int count  = 0;

    int front = 0, rear = 0;
    queue[rear++] = (POS){ x, y };
    map[y][x] = 0;

    while (front < rear)
    {
        bool bEatFish = false;
        int minX = 0, minY = 0;

        for (int end = rear; front < end; ++front)
        {
            const POS now = queue[front];

            for (int i = 0; i < 4; ++i)
            {
                const int nextX = now.x + dx[i];
                const int nextY = now.y + dy[i];

                if ((nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) || \
                    (visited[nextY][nextX] || map[nextY][nextX] > size))
                {
                    continue;
                }

                const int fishSize = map[nextY][nextX];
                visited[nextY][nextX] = visited[now.y][now.x] + 1;

                if ((fishSize != 0 && fishSize < size) && \
                    (!bEatFish || (minY > nextY || (minY == nextY && minX > nextX))))
                {
                    minX = nextX;
                    minY = nextY;
                    bEatFish = true;
                }

                else if (!bEatFish)
                    queue[rear++] = (POS){ nextX, nextY };
            }
        }

        if (bEatFish)
        {
            answer += visited[minY][minX];

            memset(visited, 0, sizeof(visited));
            map[minY][minX] = 0;

            if (++count == size)
            {
                size++;
                count = 0;
            }

            front = rear = 0;
            queue[rear++] = (POS){ minX, minY };
        }
    }

    return answer;
}

void findSharkPosition(int* outX, int* outY)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] == 9)
            {
                (*outX) = j;
                (*outY) = i;
                return;
            }
        }
    }
}

int solution()
{
    int x = 0, y = 0;
    findSharkPosition(&x, &y);
    
    return bfs(x, y);
}

int main()
{
    (void)scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            (void)scanf("%d", map[i] + j);
        }
    }

    printf("%d\n", solution());

    return 0;
}