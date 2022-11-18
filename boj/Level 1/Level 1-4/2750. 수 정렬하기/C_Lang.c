#include <stdio.h>

#define MAX_NUM 1000

void sort(int *arr, int n)
{
    // bubble sort
    int i, j, temp;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int i, n;
    int arr[MAX_NUM];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
    return 0;
}