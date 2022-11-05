#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* Result = (int*)malloc(sizeof(int) * (n + m));
    int top = 0;

    int i = 0, j = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j])
            Result[top++] = nums1[i++];       
        else
            Result[top++] = nums2[j++];
    }

    for (; i < m; i++)
        Result[top++] = nums1[i];
    
    for (; j < n; j++)
        Result[top++] = nums2[j];

    // copy
    for (i = 0; i < n + m; i++)
        nums1[i] = Result[i];
    
    free(Result);
}