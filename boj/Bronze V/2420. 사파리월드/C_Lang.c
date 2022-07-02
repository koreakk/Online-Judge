#include <stdio.h>

#define ABS(N)  ((N) > 0) ? (N) : (-(N))

int main(void) {
    long long n, m;
    scanf("%lld %lld", &n, &m);

    printf("%lld\n", ABS(n - m));
    return 0;
}