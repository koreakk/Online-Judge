#include <stdio.h>
#define MAXIDX  100001

int BFS(int N, int K)
{
    int graph[MAXIDX] = {0};
    int queue[MAXIDX];
    int step[3];
    int front = 0; int rear = 0;

    queue[rear++] = N;
    graph[N] = 1;

    while (front < rear) {
        int pop = queue[front++];
        step[0] = pop + 1;
        step[1] = pop - 1;
        step[2] = pop * 2;

        for (int i = 0; i< 3; i++) {
            int next = step[i];

            if (next < 0 || K + 1 < next) continue;

            if (graph[next] == 0) {
                graph[next] = graph[pop] + 1;
                queue[rear++] = next;
            }

            if (next == K) return graph[next] - 1;

        }
    }
    return 0;
}

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    if (N >= K) {
        printf("%d", N - K);
    }
    else {
        printf("%d \n", BFS(N, K));
    }

    return 0;
}