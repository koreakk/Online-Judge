#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _INFO
{
    struct _INFO* prev;
    int length;
    char cmd;
} INFO, * PINFO;

int D(int n) { return (n * 2) % 10000;            }
int S(int n) { return n ? --n : 9999;             }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n % 10) * 1000 + n / 10;   }

PINFO visitid[10000];
int queue[100000];

int(*next[4])(int)    = { D, S, L, R };
const char cmdName[4] = { 'D', 'S', 'L', 'R' };

void solution(const int A, const int B)
{
    if (A == B) return;

    memset(visitid, 0, sizeof(visitid));

    int front = 0, rear = 0;
    queue[rear++] = A;

    visitid[A] = (PINFO)malloc(sizeof(INFO));
    memset(visitid[A], 0, sizeof(INFO));

    while (front < rear && visitid[B] == NULL)
    {
        int n = queue[front++];

        for (int i = 0; i < 4; ++i)
        {
            int nextNum = next[i](n);
            if (visitid[nextNum])
                continue;

            PINFO nextInfo   = (PINFO)malloc(sizeof(INFO));
            nextInfo->prev   = visitid[n];
            nextInfo->length = visitid[n]->length + 1;
            nextInfo->cmd    = cmdName[i];

            visitid[nextNum] = nextInfo;
            queue[rear++]    = nextNum;
        }
    }

    size_t resSize = sizeof(char) * (visitid[B]->length + 1);

    char* res = (char*)malloc(resSize);
    memset(res, 0, resSize);

    for (PINFO curr = visitid[B]; curr && curr != A; curr = curr->prev)
        res[curr->length - 1] = curr->cmd;

    printf("%s\n", res);
    free(res);

    // free
    for (int i = 0; i < 10000; ++i)
        if (visitid[i]) free(visitid[i]);
}

int main(void)
{
    int T, A, B;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &A, &B);
        solution(A, B);
    }

    return 0;
}
