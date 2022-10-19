#define MIN_NUM -10000

int maxSubArray(int* nums, int numsSize) {
    int maxSum = MIN_NUM;
    int currentSum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
        
        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}