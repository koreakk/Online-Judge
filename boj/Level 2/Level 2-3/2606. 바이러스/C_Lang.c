#include <stdio.h>
#include <stdbool.h>


int BFS(int n, int graph[][101])
{
    bool visited[101] = {false};
    int queue[101];
    int front = 0, rear = 0;

    queue[rear++] = 1;
    visited[1] = true;

    while (front < rear) {
        int pop = queue[front++];

        for (int i = 2; i <= n; i++) {
            if (!visited[i] && graph[pop][i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    return rear - 1;
}


int main(void)
{
    int i, a, b;
    int n, k;
    int graph[101][101] = {0, };

    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    printf("%d \n", BFS(n, graph));
}