#include <stdio.h>


int DFS(int i, int j, int N, int graph[][25]);
void sort(int array[], int left, int right);


void solution(int N, int graph[][25])
{
    int counts[400];
    int rear = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 1) {
                counts[rear++] = DFS(i, j, N, graph);
            }
        }
    }
    sort(counts, 0, rear - 1);

    printf("%d \n", rear);
    for (int i = 0; i < rear; i++) {
        printf("%d \n", counts[i]);
    }
}


int main(void)
{
    int N;
    int graph[25][25];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    solution(N, graph);
    return 0;
}


int DFS(int i, int j, int N, int graph[][25])
{
    if (i < 0 || N <= i || j < 0 || N <= j) return 0;
    if (graph[i][j] == 0) return 0;
    
    graph[i][j] = 0;
    return DFS(i + 1, j, N, graph) +
           DFS(i - 1, j, N, graph) +
           DFS(i, j + 1, N, graph) +
           DFS(i, j - 1, N, graph) + 1;
}


void sort(int array[], int left, int right)
{
    int i = left, j = right;
    int pivot = array[left + (right - left) / 2];
    int temp;

    while (i <= j) {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j) sort(array, left, j);
    if (i < right) sort(array, i, right);
}