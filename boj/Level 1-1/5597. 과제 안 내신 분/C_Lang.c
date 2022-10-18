#include <stdio.h>
#include <stdbool.h>


int main(void) {
    bool attendance_table[31] = { false, };
    int n;

    for (int i = 0; i < 28; i++) {
        scanf("%d", &n);
        attendance_table[n] = true;
    }

    for (int i = 1; i <= 30; i++) {
        if (! attendance_table[i])
            printf("%d\n", i);
    }

    return 0;
}