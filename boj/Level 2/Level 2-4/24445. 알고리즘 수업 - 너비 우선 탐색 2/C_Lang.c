#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int vertex;
    struct node* link;
} Node;

Node* graph[100001];
int visited[100001];
int count;

void BFS(int R);
void insertGraph(int A, int B);
Node* mergeTwoLists(Node* l1, Node* l2);
Node* sortList(Node* head);


int main(void)
{
    int a, b, i;
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    for (i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        insertGraph(a, b);
        insertGraph(b, a);
    }

    BFS(R);
    for (i = 1; i <= N; i++) {
        printf("%d \n", visited[i]);
    }
    return 0;
}


void BFS(int R)
{
    int queue[100001];
    int front = 0, rear = 0;

    queue[rear++] = R;
    visited[R] = ++count;
    
    while (front < rear) {
        int pop = queue[front++];
        Node* node = sortList(graph[pop]);

        while (node != NULL) {
            if (!visited[node->vertex]) {
                visited[node->vertex] = ++count;
                queue[rear++] = node->vertex;
            }
            node = node->link;
        }
    }
}


void insertGraph(int A, int B)
{
    Node* head = (Node *)malloc(sizeof(Node));
    head->vertex = B;
    head->link = graph[A];
    graph[A] = head;
}


Node* mergeTwoLists(Node* l1, Node* l2)
{
    Node* temp;
    if (l1 != NULL && l2 != NULL) {
        if (l1->vertex < l2->vertex) {
            temp = l1;
            l1 = l2;
            l2 = temp;
        }
        l1->link = mergeTwoLists(l1->link, l2);
    }

    if (l1 == NULL) return l2;
    else return l1;
}


Node* sortList(Node* head)
{
    if (head == NULL || head->link == NULL)
        return head;
    
    Node *half;
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->link != NULL) {
        half = slow;
        slow = slow->link;
        fast = fast->link->link;
    }
    half->link = NULL;

    Node* A = sortList(head);
    Node* B = sortList(slow);

    return mergeTwoLists(A, B);
}