#include <stdio.h>
#include <stdbool.h>

void sort(int* arr, int left, int right);

int solution(int n, int* arr)
{
    int result = 0;
    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        result += arr[i] * (n - i);
    }
    return result;
}

int main(void)
{
    int n;
    int arr[1000];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    printf("%d", solution(n, arr));
    return 0;
}

void sort(int* arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[left + (right - left) / 2];
    int temp;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }
    
    if (left < j) sort(arr, left, j);
    if (i < right) sort(arr, i, right);
}