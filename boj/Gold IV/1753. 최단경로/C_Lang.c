#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF       ((int)1e9)

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
    newNode->next   = NULL;

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

void deleteGraph(Graph* graph)
{
    if (graph == NULL) return;

    const int vertices = graph->numVertices;
    Node** adjLists = graph->adjLists;

    for (int i = 0; i <= vertices; ++i)
        deleteList(adjLists[i]);
    free(graph);
}

// heap
typedef struct _HeapNode
{
    int id;
    int item;
} HeapNode;

typedef struct _Heap
{
    int heapSize;
    int length;
    HeapNode* array;
} Heap;

Heap* createHeap(int size)
{
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    assert(heap != NULL);

    heap->heapSize = size;
    heap->length = 0;
    heap->array = (HeapNode*)malloc(sizeof(HeapNode) * size);
    assert(heap->array != NULL);

    return heap;
}

void deleteHeap(Heap* heap)
{
    if (heap == NULL) return;

    if (heap->array)
        free(heap->array);
    free(heap);
}

void siftDown(Heap* heap, int startPos, int pos)
{
    HeapNode* heapArray = heap->array;
    HeapNode  newitem = heapArray[pos];

    while (pos > startPos)
    {
        int parentPos = (pos - 1) >> 1;
        HeapNode parent = heapArray[parentPos];
        if (newitem.id < parent.id)
        {
            heapArray[pos] = parent;
            pos = parentPos;
        }
        else break;
    }
    heapArray[pos] = newitem;
}

void siftUp(Heap* heap, int pos)
{
    int endPos = heap->length;
    int startPos = pos;
    HeapNode* heapArray = heap->array;
    HeapNode  newitem = heapArray[pos];

    int childPos = 2 * pos + 1;
    while (childPos < endPos)
    {
        int rightPos = childPos + 1;
        if (rightPos < endPos && !(heapArray[childPos].id < heapArray[rightPos].id))
            childPos = rightPos;

        heapArray[pos] = heapArray[childPos];
        pos = childPos;
        childPos = 2 * pos + 1;
    }

    heapArray[pos] = newitem;
    siftDown(heap, startPos, pos);
}

void heapPush(Heap* heap, HeapNode item)
{
    assert(heap->heapSize > heap->length);
    heap->array[heap->length++] = item;
    siftDown(heap, 0, heap->length - 1);
}

HeapNode heapPop(Heap* heap)
{
    HeapNode* heapArray = heap->array;
    HeapNode  lastElt = heapArray[--heap->length];
    if (heap->length)
    {
        HeapNode returnItem = heapArray[0];
        heapArray[0] = lastElt;
        siftUp(heap, 0);
        return returnItem;
    }
    return lastElt;
}

int* Dijkstra(const Graph* graph, int source)
{
    size_t distSize = graph->numVertices + 1;
    int* dist = (int*)malloc(sizeof(int) * distSize);
    assert(dist != NULL);

    for (int i = 1; i < distSize; ++i)
        dist[i] = INF;
    dist[source] = 0;

    Heap* hq = createHeap(200001);
    heapPush(hq, (HeapNode) { 0, source });

    while (hq->length)
    {
        const HeapNode now = heapPop(hq);
        const int vertex = now.item;
        const int weight = now.id;

        for (Node* node = graph->adjLists[vertex]; node; node = node->next)
        {
            const int destVertex = node->vertex;
            const int distance = node->weight + weight;

            if (distance >= dist[destVertex])
                continue;

            dist[destVertex] = distance;
            heapPush(hq, (HeapNode) { distance, destVertex });
        }
    }

    deleteHeap(hq);
    return dist;
}

int main()
{
    int N, M, K;
    scanf("%d %d", &N, &M);
    scanf("%d", &K);

    Graph* graph = createGraph(N);
    for (int i = 0; i < M; ++i)
    {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    int* dist = Dijkstra(graph, K);
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }

    free(dist);
    deleteGraph(graph);
    return 0;
}