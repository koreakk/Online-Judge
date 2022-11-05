#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH  1000000000

int solution(int n, int m, int nums[]) {
    int start = 0, end = MAXLENGTH;
    int mid;
    long long length;

    while (start <= end) {
        mid = start + (end - start) / 2;
        length = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mid)
                length += nums[i] - mid;
        }

        if (length >= m)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return end;
}


int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int* nums = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", nums + i);
    }

    printf("%d\n", solution(n, m, nums));
    free(nums);
    return 0;
}