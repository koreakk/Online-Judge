#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int coordInfos[100000][4];
int table[1025][1025];

int* solution(int tableSize, int coordInfosSize)
{
    for (int i = 1; i <= tableSize; ++i)
        for (int j = 2; j <= tableSize; ++j)
            table[i][j] += table[i][j - 1];

    for (int i = 2; i <= tableSize; ++i)
        for (int j = 1; j <= tableSize; ++j)
            table[i][j] += table[i - 1][j];

    int* results = (int*)malloc(sizeof(int) * coordInfosSize);
    assert(results != NULL);

    for (int i = 0; i < coordInfosSize; ++i) {
        const int* coordInfo = coordInfos[i];

        const int x1 = coordInfo[0];
        const int y1 = coordInfo[1];
        const int x2 = coordInfo[2];
        const int y2 = coordInfo[3];

        results[i] = table[x2][y2] - table[x1 - 1][y2] - table[x2][y1 - 1] + table[x1 - 1][y1 - 1];
    }

    return results;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", table[i] + j);

    for (int i = 0; i < M; ++i) {
        int* coordInfo = coordInfos[i];

        scanf("%d %d %d %d",
            coordInfo, coordInfo + 1,
            coordInfo + 2, coordInfo + 3
        );
    }

    int* results = solution(N, M);
    for (int i = 0; i < M; ++i)
        printf("%d\n", results[i]);

    free(results);
    return 0;
}