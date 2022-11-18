#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSequence(int sequence[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", sequence[i]);
    putchar('\n');
}

void dfs(int idx, int start, int k, int nums[], int sequence[]) {
    if (idx == 6) {
        printSequence(sequence, 6);
        return;
    }

    for (int i = start; i < k; i++) {
        sequence[idx] = nums[i];
        dfs(idx + 1, i + 1, k, nums, sequence);
    }
}

void solution(int k, int nums[]) {
    int* sequence = (int*)malloc(sizeof(int) * 6);
    dfs(0, 0, k, nums, sequence);
    free(sequence);
    putchar('\n');
}

int main(void) {
    int k;
    while (1) {
        scanf("%d", &k);
        if (!k) break;

        int* nums = (int*)malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++)
            scanf("%d", nums + i);

        solution(k, nums);
        free(nums);
    }
    return 0;
}