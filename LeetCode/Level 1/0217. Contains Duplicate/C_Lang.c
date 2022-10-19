#include <stdbool.h>
#include <stdlib.h>

int Compare(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), Compare);

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1])
            return true;
    }

    return false;
}