#include <stdio.h>

#define BLACK   1
#define WHITE   0

int is_color(int s, int N, int start, int end, int i, int j)
{
    int num = 1;
    while (s-- > 0) {
        int _i = (i / num) % N;
        int _j = (j / num) % N;
        if (start <= _i && _i <= end && start <= _j && _j <= end)
            return BLACK;
        num *= N;
    }
    return WHITE;
}

void solution(int s, int N, int K, int R1, int R2, int C1, int C2)
{
    int start = (N - K) / 2;
    int end = start + K - 1;
    int i, j;
    for (i = R1; i <= R2; i++) {
        for (j = C1; j <= C2; j++)
            printf("%d", is_color(s, N, start, end, i, j));
        printf("\n");
    }
}

int main(void) {
    int s, N, K, R1, R2, C1, C2;
    scanf("%d %d %d %d %d %d %d", &s, &N, &K, &R1, &R2, &C1, &C2);
    solution(s, N, K, R1, R2, C1, C2);
    return 0;
}