#include <stdio.h>

#define MAX(left, right) (((left) > (right)) ? (left) : (right))
#define EXTRACT_BIT(n, loc, area)      (((n) >> (loc)) & (area))
#define DX(block, idx)   EXTRACT_BIT((block), ((idx) << 2),     0b11)
#define DY(block, idx)   EXTRACT_BIT((block), ((idx) << 2) + 2, 0b11)

typedef unsigned short block_t;

const block_t BLOCK[21] = {
    0xc840, 0x3210, 0x5410,
    0x6510, 0x8541, 0x6510,
    0x8541, 0x9851, 0x6540,
    0x8410, 0x6210, 0x5421,
    0x9540, 0x9840, 0x4210,
    0x9510, 0x6542, 0x5210,
    0x9541, 0x6541, 0x8540
};

int map[500][500];
int N, M;

int score(const int x, const int y, const block_t block)
{
    int answer = 0;

    for (int i = 0; i < 4; ++i)
    {
        const int currX = x + DX(block, i);
        const int currY = y + DY(block, i);

        if (currX < 0 || currX >= M || currY < 0 || currY >= N)
            return 0;

        answer += map[currY][currX];
    }

    return answer;
}

int solution()
{
    int bestScore = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < 21; ++k)
            {
                const int currScore = score(j, i, BLOCK[k]);
                bestScore = MAX(bestScore, currScore);
            }
        }
    }

    return bestScore;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            scanf("%d", map[i] + j);
        }
    }

    printf("%d\n", solution());

    return 0;
}