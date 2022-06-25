#include <stdio.h>
#include <string.h>

#define STACK_SIZE 10000

int stack[STACK_SIZE];
int idx = -1;

int empty();
void push(int n);
int pop();
int size();
int top();


int main(void)
{
    int n, i, num;
    char str[10];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);

        if (strcmp(str, "push") == 0) {
            scanf("%d", &num);
            push(num);
        }
        else if (strcmp(str, "pop") == 0)
            printf("%d \n", pop());
        else if (strcmp(str, "size") == 0)
            printf("%d \n", size());
        else if (strcmp(str, "empty") == 0)
            printf("%d \n", empty());
        else if (strcmp(str, "top") == 0)
            printf("%d \n", top());
    }
    return 0;
}

int empty()
{
    return idx == -1;
}

void push(int n)
{
    stack[++idx] = n;
}

int pop()
{
    if (empty()) return -1;
    return stack[idx--];   
}

int size()
{
    return idx + 1;
}

int top()
{
    if (empty()) return -1;
    return stack[idx];
}