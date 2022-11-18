#include <stdio.h>

int dp[100050], queue[100050], front = -1, rear = -1;

int solution(int n, int k)
{
    if (k <= n) {
        return n - k;
    }

    const int last    = k + 2;
    const int next[2] = { -1, 1 };

    queue[++rear] = n;
    dp[n] = 1;

    while (front < rear) {
        const int pos      = queue[++front];
        const int time     = dp[pos];
        const int nextTime = time + 1;

        if (pos == k) {
            break;
        }

        int nextpos = pos * 2;
        for (; nextpos < last && dp[nextpos] == 0; nextpos *= 2) {
            dp[nextpos]   = time;
            queue[++rear] = nextpos;
        }

        for (int i = 0; i < 2; ++i) {
            nextpos = pos + next[i];

            if ((nextpos >= 0 && nextpos < last) && dp[nextpos] == 0) {
                dp[nextpos]   = nextTime;
                queue[++rear] = nextpos;
            }
        }
    }

    return dp[k] - 1;
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d\n", solution(n, k));

    return 0;
}