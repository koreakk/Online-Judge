#include <stdio.h>

int solution(int n) {
    int answer = 0;
    n /= 5;
    while (n) {
        answer += n;
        n /= 5;
    }
    return answer;
}

int main(void) {
    int n;
    scanf("%d", &n);

    printf("%d\n", solution(n));
    return 0;
}