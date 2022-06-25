#include <stdio.h>

int map[101];
int mov[101];

int BFS()
{
    int queue[101];
    int front = 0, rear = 0;

    queue[rear++] = 1;
    while (front < rear) {
        int pop = queue[front++];

        for (int i = 1; i <= 6; i++) {
            int next = pop + i;
            if (next > 100) break;

            if (mov[next])
                next = mov[next];
            
            if (map[next] == 0) {
                map[next] = map[pop] + 1;
                queue[rear++] = next;

            if (next == 100)
                return map[next];
            }
        }
    }
}

int main(void)
{
    int sum;
    int N, M;
    scanf("%d %d", &N, &M);
    sum = N + M;
    for (int i = 0; i < sum; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        mov[x] = y;
    }
    printf("%d \n", BFS());
    return 0;
}