#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct _Node
{
    int vertex;
    struct _Node* next;
} Node;

Node* graph[100001];
bool visited[100001];

Node* createNode(int vertex)
{
    Node* newNode   = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->vertex = vertex;
    newNode->next   = NULL;

    return newNode;
}

void deleteAdjList(Node* root)
{
    Node* currNode = root;
    Node* nextNode = NULL;

    for (; currNode; currNode = nextNode)
    {
        nextNode = currNode->next;
        free(currNode);
    }
}

void addEdge(int src, int dest)
{    
    Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src]    = newNode;
}

void solution(int* answer, int root)
{
    visited[root] = true;

    for (Node* node = graph[root]; node; node = node->next)
    {
        int next = node->vertex;

        if (!visited[next])
        {
            answer[next - 2] = root;
            solution(answer, next);
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N - 1; ++i)
    {
        int v, u;
        scanf("%d %d", &v, &u);

        addEdge(v, u);
        addEdge(u, v);
    }

    int* result = (int*)malloc(((size_t)N - 1) * sizeof(int));
    assert(result != NULL);
    solution(result, 1);

    for (int i = 0; i < N - 1; ++i) {
        printf("%d\n", result[i]);
    }

    free(result);
    for (int i = 0; i < N; ++i) {
        deleteAdjList(graph[i]);
    }

    return 0;
}