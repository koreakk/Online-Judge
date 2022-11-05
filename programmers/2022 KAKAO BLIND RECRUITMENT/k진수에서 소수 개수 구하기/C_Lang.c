#include <stdio.h>

int isPrime(size_t n)
{
    if (n < 2)
        return 0;
    
    for (size_t i = 2; (i * i) <= n; i++) {
        if ((n % i) == 0)
            return 0;
    }
    return 1;
}


int solution(int n, int k)
{

    size_t conv = 0;
    size_t mod = 0;
    size_t base = 1;
    int answer = 0;

    while (n != 0) {
        mod = n % k;

        if (mod == 0) {
            answer += isPrime(conv);
            conv = 0;
            base = 1;
        }
        else {
            conv += mod * base;
            base *= 10;
        }

        n = n / k;
    }
    answer += isPrime(conv);


    return answer;
}