#include <stdio.h>

int solution(int N, int r, int c)
{
    int result = 0;
    int num = 1;
    while (N-- > 0) {
        int i = (r / num) % 2;
        int j = (c / num) % 2;

        result += (i * 2 + j) * num * num;
        num *= 2;
    }
    return result;
}

int main(void)
{
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d \n", solution(N, r, c));
    return 0;
}