#include <stdio.h>
#include <stdbool.h>


void DFS(int N, int V, int graph[][1001], bool visited[])
{
    printf("%d ", V);
    visited[V] = true;

    for (int i = 0; i <= N; i++) {
        if (!visited[i] && graph[V][i]) {
            DFS(N, i, graph, visited);
        }
    }
}

void BFS(int N, int V, int graph[][1001])
{
    bool visited[1001] = {false};
    int queue[1001];
    int front = 0, rear = 0;

    queue[front] = V; rear++;
    visited[V] = true;

    while (front < rear) {
        int pop = queue[front++];       
        printf("%d ", pop);

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && graph[pop][i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

int main(void)
{
    int i, a, b;
    int N, M, V;
    int graph[1001][1001] = {0, };
    bool visited[1001] = {false};

    scanf("%d %d %d", &N, &M, &V);
    for (i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    DFS(N, V, graph, visited);
    printf("\n");
    BFS(N, V, graph);
    return 0;
}