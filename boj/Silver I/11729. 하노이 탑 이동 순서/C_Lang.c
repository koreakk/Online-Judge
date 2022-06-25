#include <stdio.h>

void hanoi_movement(int num, int now, int move);

void solution(int k)
{
    int total = 1;
    int i;

    for (i = 0; i < k; i++) {
        total *= 2;
    }
    total--;

    printf("%d \n", total);
    hanoi_movement(k, 1, 3);
}

int main(void)
{
    int k;
    scanf("%d", &k);
    solution(k);
    return 0;
}

void hanoi_movement(int num, int now, int move) {
    if (num == 1) {
        printf("%d %d \n", now, move);
        return;
    }
    hanoi_movement(num - 1, now, 6 - (now + move));
    printf("%d %d \n", now, move);
    hanoi_movement(num - 1, 6 - (now + move), move);
}