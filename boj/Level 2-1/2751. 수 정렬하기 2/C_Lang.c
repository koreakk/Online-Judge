#include <stdio.h>

#define MAX_NUM 1000000

void sort(int *arr, int low, int high, int *temp)
{
    /* marge sort */

    // base condition
    if (low >= high) return;

    // divide
    int mid = low + (high - low) / 2;
    
    // conquer
    sort(arr, low, mid, temp);
    sort(arr, mid + 1, high, temp);

    // combine
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    // copy
    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

int main(void)
{
    int i, n;
    int arr[MAX_NUM];
    int temp[MAX_NUM];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, 0, n - 1, temp);

    for (i = 0; i < n; i++) {
        printf("%d \n", arr[i]);
    }
    return 0;
}