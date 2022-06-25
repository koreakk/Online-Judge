#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int solution(int n) {
    const int base = 3;

    int answer = 0;
    
    while (n) {
        answer *= base;
        answer += n % base;
        n /= base;
    }

    return answer;
}