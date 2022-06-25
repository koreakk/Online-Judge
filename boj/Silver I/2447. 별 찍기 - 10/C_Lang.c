# include <stdio.h>
# include <stdbool.h>

bool is_star(int n, int i, int j)
{
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
        return false;
    else if (n == 1)
        return true;
    is_star(n / 3, i, j);
}

void solution(int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (is_star(n / 3, i, j))
                putchar('*');
            else
                putchar(' ');
        }
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