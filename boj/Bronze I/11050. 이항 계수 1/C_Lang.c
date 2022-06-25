#include <stdio.h>


int factorial(int n) {
    if (n <= 1)
        return 1;
    
    return n * factorial(n - 1);
}

int solution(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    printf("%d\n", solution(n, k));
    return 0;
}