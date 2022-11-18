#include <stdio.h>

int array[100000], sum_array[100001];

int main(void) {
    int n, m, start, end;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", array + i);
    
    for (int i = 0; i < n; i++)
        sum_array[i + 1] = sum_array[i] + array[i];
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &start, &end);
        printf("%d\n", sum_array[end] - sum_array[start - 1]);
    }

    return 0;
}