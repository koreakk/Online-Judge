#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int vertex;
    struct node* link;
} Node;


Node* graph[200050];
int visited[200050];


void initGraph(int V);
void insertGraph(int A, int B);
void DFS(int n);
bool isBipartiteGraph(int V);


void solution(int V, int E)
{
    int i;
    for (i = 1; i <= V; i++) {
        if (!visited[i]) DFS(i);
    }

    if (isBipartiteGraph(V))
        printf("YES \n");
    else printf("NO \n");

    for (i = 1; i <= V; i++) {
        visited[i] = 0;
    }
}

int main(void)
{
    int a, b, i;
    int K, V, E;
    scanf("%d", &K);
    while (K-- > 0) {
        scanf("%d %d", &V, &E);
        initGraph(V);
        for (i = 0; i < E; i++) {
            scanf("%d %d", &a, &b);
            insertGraph(a, b);
            insertGraph(b, a);
        }
        solution(V, E);
    }
    return 0;
}

void initGraph(int V)
{
    for (int i = 1; i <= V; i++) {
        graph[i] = NULL;
    }
}

void insertGraph(int A, int B)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = B;
    node->link = graph[A];
    graph[A] = node;
}

void DFS(int n)
{   
    if (!visited[n])
        visited[n] = 1;

    Node* node = graph[n];
    while (node != NULL) {
        if (!visited[node->vertex]) {
            visited[node->vertex] = (visited[n] == 1) ? 2 : 1;
            DFS(node->vertex);
        }
        node = node->link;
    }
}

bool isBipartiteGraph(int V)
{
    for (int i = 1; i <= V; i++) {
        Node* node = graph[i];
        while (node != NULL) {
            if (visited[i] == visited[node->vertex])
                return false;
            node = node->link;
        }

    }
    return true;
}