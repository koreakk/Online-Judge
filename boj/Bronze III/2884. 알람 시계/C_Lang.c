#include <stdio.h>

int main(void)
{
    int H, M;
    scanf("%d %d", &H, &M);

    if (M >= 45) {
        M -= 45;
    }
    else {
        M += 15;
        H = (H == 0) ? H + 23 : H - 1;
    }
    printf("%d %d \n", H, M);
    return 0;
}