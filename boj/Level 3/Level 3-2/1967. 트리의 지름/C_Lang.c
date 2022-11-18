#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node
{
    int vertex;
    int weight;
    struct _Node* next;
} Node;

typedef struct _Graph
{
    int numVertices;
    Node** adjLists;
} Graph;

Node* createNode(int vertex, int weight)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int vertices)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    assert(graph != NULL);

    graph->numVertices = vertices;

    const size_t adjListsSize = sizeof(Node*) * (size_t)(vertices + 1);
    graph->adjLists = (Node**)malloc(adjListsSize);
    assert(graph->adjLists != NULL);

    memset(graph->adjLists, 0, adjListsSize);
    return graph;
}

void addEdge(Graph* graph, int source, int destination, int weight)
{
    Node* node = createNode(destination, weight);

    node->next = graph->adjLists[source];
    graph->adjLists[source] = node;
}

void deleteList(Node* list)
{
    Node* currNode = list;
    Node* nextNode = NULL;

    for (; currNode; currNode = nextNode)
    {
        nextNode = currNode->next;
        free(currNode);
    }
}

void deleteGraph(Graph** graph)
{
    const int vertices = (*graph)->numVertices;
    Node** adjLists = (*graph)->adjLists;

    for (int i = 0; i <= vertices; ++i)
    {
        deleteList(adjLists[i]);
    }

    free((*graph));
    (*graph) = NULL;
}

int dfs(const Graph* graph, int* visited, int vertex, int cost)
{
    visited[vertex] = cost;
    int maxVertex = vertex;

    for (Node* node = graph->adjLists[vertex]; node; node = node->next)
    {
        if (visited[node->vertex]) continue;
        int currVertex = dfs(graph, visited, node->vertex, node->weight + cost);

        maxVertex = visited[maxVertex] > visited[currVertex] ? maxVertex : currVertex;
    }

    return maxVertex;
}

int solution(const Graph* graph)
{
    const int V = graph->numVertices;

    const size_t visitedSize = sizeof(int) * ((size_t)V + 1);
    int* visited = (int*)malloc(visitedSize);
    assert(visited != NULL);
    memset(visited, 0, visitedSize);

    int maxVetex = dfs(graph, visited, 1, 1);
    memset(visited, 0, visitedSize);
    int result = visited[dfs(graph, visited, maxVetex, 1)] - 1;

    free(visited);
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    Graph* graph = createGraph(n);
    int src, dest, weight;

    for (int i = 1; i < n; ++i) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
        addEdge(graph, dest, src, weight);
    }

    printf("%d\n", solution(graph));
    deleteGraph(&graph);
    return 0;
}