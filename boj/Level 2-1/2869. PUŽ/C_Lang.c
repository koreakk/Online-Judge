#include <stdio.h>

int main(void)
{
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);

    V = (V - B) - 1;
    int answer = (V / (A - B)) + 1;

    printf("%d\n", answer);
    return 0;
}