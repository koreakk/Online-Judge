#include <stdio.h>
#include <stdbool.h>

typedef struct number {
    int num0;
    int num1;
} Number;

Number dp[41];
bool visited[41];

Number fibonacci(int n)
{
    if (n == 0)
        return (Number){1, 0};
    if (n == 1)
        return (Number){0, 1};

    if (!visited[n]) {
        visited[n] = true;
        Number fib1 = fibonacci(n-1);
        Number fib2 = fibonacci(n-2);
        dp[n].num0 = fib1.num0 + fib2.num0;
        dp[n].num1 = fib1.num1 + fib2.num1;
    }

    return dp[n];
}

int main(void)
{
    int T, N;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        Number result = fibonacci(N);
        printf("%d %d \n", result.num0, result.num1);
    }
}