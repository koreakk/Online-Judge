#include <stdio.h>
#include <stdbool.h>

typedef struct time
{
    int start;
    int end;

} Time;

bool key(Time* t1, Time* t2);
void sort(Time* arr, int left, int right);

int solution(int n, Time* schedule)
{
    int end, count, i;
    sort(schedule, 0, n - 1);
    

    end = schedule[0].end;
    count = 1;
    for (i = 1; i < n; i++) {
        if (schedule[i].start >= end) {
            count++;
            end = schedule[i].end;
        }
    }
    return count;
}

int main(void)
{
    int n, i, result;
    scanf("%d", &n);
    Time schedule[n];
    for (i = 0; i < n; i++) {
        scanf("%d %d", &schedule[i].start, &schedule[i].end);
    }

    result = solution(n, schedule);
    printf("%d", result);
    return 0;
}

void sort(Time* arr, int left, int right)
{
    // quick sort
    int i = left, j = right;
    Time pivot = arr[left + (right - left) / 2];
    Time temp;

    while (i <= j) {
        while (key(&arr[i], &pivot)) i++;    // arr[i] >= pivot
        while (key(&pivot, &arr[j])) j--;    // arr[j] <= pivot

        // SWAP
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

bool key(Time* t1, Time* t2)
{
    return (t1->end < t2->end) || (t1->end == t2->end && t1->start < t2->start);
}