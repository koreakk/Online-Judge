#include <stdio.h>

typedef struct color {
    int white;
    int blue;
} Color;

Color solution(int N, int x, int y, int graph[][128])
{
    if (N == 0) {
        if (graph[x][y]) return (Color){0, 1};
        else return (Color){1, 0};
    }

    int half = N / 2;
    int _x = x + half, _y = y + half;
    Color A = solution(half, x, y, graph);
    Color B = solution(half, _x, y, graph);
    Color C = solution(half, x, _y, graph);
    Color D = solution(half, _x, _y, graph);

    Color result;
    result.blue = A.blue + B.blue + C.blue + D.blue;
    result.white = A.white + B.white + C.white + D.white;
    
    if (!result.white) return (Color){0, 1};
    if (!result.blue) return (Color){1, 0};
    return result;
}

int main(void)
{
    int N;
    int graph[128][128];
    Color result;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    result = solution(N, 0, 0, graph);
    printf("%d\n", result.white);
    printf("%d", result.blue);
    return 0;
}