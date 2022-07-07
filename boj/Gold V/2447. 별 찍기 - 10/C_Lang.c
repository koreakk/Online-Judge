# include <stdio.h>
# include <stdbool.h>

void putstar(int n, int i, int j)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        putchar(' ');
        return;
    }
    else if (n == 1) {
        putchar('*');
        return;
    }
    putstar(n / 3, i, j);
}

void solution(int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            putstar(n / 3, i, j);
        putchar('\n');
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    solution(n);
    return 0;
}