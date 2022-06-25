#include <stdio.h>

int fibonacci_numbers(int n)
{
    if (n < 2) return n;
    return fibonacci_numbers(n - 1) + fibonacci_numbers(n - 2);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci_numbers(n));
    return 0;
}