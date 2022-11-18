#include <stdio.h>

typedef long long int64;

int64 fib(int64 n, int64 mod)
{
    const int64 P = mod / 10 * 15;

    int64 x = 0, y = 1;
    int64 temp;

    for (int64 i = 0, end = n % P; i < end; ++i) {
        temp = (x + y) % mod;
        x = y;
        y = temp;
    }

    return x;
}

int main()
{
    int64 n;
    scanf("%lld", &n);

    printf("%lld\n", fib(n, 1000000));
    return 0;
}