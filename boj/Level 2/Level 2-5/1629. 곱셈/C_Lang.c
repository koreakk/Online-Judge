#include <stdio.h>

int power(int base, int exp, int mod)
{
    int result = 1;

    for (; exp; exp /= 2)
    {
        if (exp % 2 != 0)
            result = ((long long)result * base) % mod;

        base = ((long long)base * base) % mod;
    }

    return result;
}

int main()
{
    int base, exp, mod;
    scanf("%d %d %d", &base, &exp, &mod);

    printf("%d\n", power(base, exp, mod));

    return 0;
}