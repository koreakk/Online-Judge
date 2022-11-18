#include <stdio.h>

#define INT(x) ((x) - 'A')
#define LEFT_CHILD  0
#define RIGHT_CHILD 1

char childInfo[26][2];

void PrintPreorderTraversal(char x)
{
    if (x == '.') return;

    putchar(x);
    PrintPreorderTraversal(childInfo[INT(x)][LEFT_CHILD]);
    PrintPreorderTraversal(childInfo[INT(x)][RIGHT_CHILD]);
}

void PrintInorderTraversal(char x)
{
    if (x == '.') return;

    PrintInorderTraversal(childInfo[INT(x)][LEFT_CHILD]);
    putchar(x);
    PrintInorderTraversal(childInfo[INT(x)][RIGHT_CHILD]);
}

void printPostorderTraversal(char x)
{
    if (x == '.') return;

    printPostorderTraversal(childInfo[INT(x)][LEFT_CHILD]);
    printPostorderTraversal(childInfo[INT(x)][RIGHT_CHILD]);
    putchar(x);
}

int main()
{
    int N;
    scanf("%d", &N), getchar();

    for (int i = 0; i < N; ++i) {
        char src, left, right;
        scanf("%c %c %c", &src, &left, &right), getchar();

        childInfo[INT(src)][LEFT_CHILD]  = left;
        childInfo[INT(src)][RIGHT_CHILD] = right;
    }

    PrintPreorderTraversal('A'),   putchar('\n');
    PrintInorderTraversal('A'),   putchar('\n');
    printPostorderTraversal('A'), putchar('\n');

    return 0;
}