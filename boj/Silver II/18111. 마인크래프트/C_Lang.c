#include <stdio.h>

void solution(int N, int M, int B, int heights[][501])
{
    int i, j;
    int best_time = 1000000000;
    int best_height = -1;
    int max_height = 0;
    int min_height = 256;
    int used_blocks;
    int height;
    int time;
    int diff;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            max_height = (max_height > heights[i][j]) ? max_height : heights[i][j];
            min_height = (min_height < heights[i][j]) ? min_height : heights[i][j];
        }
    }

    for (height = max_height; height >= min_height; height--) {
        used_blocks = 0;
        time = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                diff = heights[i][j] - height;
                time += (diff < 0) ? -diff : diff * 2;
                used_blocks -= diff;
            }
        }

        if (B < used_blocks) continue;
        if (best_time > time) {
            best_time = time;
            best_height = height;
        }
    }
    printf("%d %d", best_time, best_height);
}

int main(void)
{
    int i, j;
    int N, M, B;
    int heights[501][501];

    scanf("%d %d %d", &N, &M, &B);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &heights[i][j]);
        }
    }
    solution(N, M, B, heights);
    return 0;
}