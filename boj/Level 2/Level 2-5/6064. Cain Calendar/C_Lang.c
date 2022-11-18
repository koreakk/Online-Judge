#include <stdio.h>

int lcm(int n1, int n2)
{
    int mul = n1 * n2;
    int tmp = 0;

    while (n2) {
        tmp = n1 % n2;
        n1 = n2;
        n2 = tmp;
    }
    return mul / n1;
}

int solution(int M, int N, int x, int y)
{
    int l = lcm(M, N);

    for (; x <= l; x += M) {
        if ((x - 1) % N + 1 == y)
            return x;
    }

    return -1;
}

int main(void)
{
    int T;
    int M, N, x, y;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        printf("%d\n", solution(M, N, x, y));
    }

    return 0;
}