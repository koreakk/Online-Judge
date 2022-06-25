#include <stdio.h>

#define MAX_SIZE 10001

int main(void)
{
    int i, j, data, n;
    int count[MAX_SIZE] = {0, };

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &data);
        count[data]++;
    }

    for (i = 1; i < MAX_SIZE; i++) {
        for (j = 0; j < count[i]; j++) {
            printf("%d \n", i);
        }
    }
    return 0;
}