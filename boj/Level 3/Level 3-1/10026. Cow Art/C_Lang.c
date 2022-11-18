#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool visited[100][100];
char map[100][100];
int N;

void DFS(const int x, const int y, bool(*compare)(const char, const char))
{
    visited[y][x] = true;

    // up, left, right, down 
    const int dx[] = { 0, 1, -1, 0 };
    const int dy[] = { -1, 0, 0, 1 };

    for (int i = 0; i < 4; ++i)
    {
        const int nextX = x + dx[i];
        const int nextY = y + dy[i];

        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
            continue;

        if (visited[nextY][nextX] || !compare(map[y][x], map[nextY][nextX]))
            continue;

        DFS(nextX, nextY, compare);
    }
}

int solution(bool(*compare)(const char, const char))
{
    memset(visited, 0, sizeof(visited));

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j])
                continue;

            DFS(j, i, compare);
            count++;
        }
    }

    return count;
}

bool cmp1(const char A, const char B)
{
    return A == B;
}

bool cmp2(const char A, const char B)
{
    return (A == B) || \
        (A == 'R' && B == 'G') || \
        (A == 'G' && B == 'R');
}


int main()
{
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%1c", map[i] + j);
        }
        getchar();
    }

    printf("%d %d\n", solution(cmp1), solution(cmp2));

    return 0;
}