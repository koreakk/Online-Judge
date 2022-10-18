#include <stdio.h>

int nums[100001];
int size = 0;

void push(int num) {
    int child = ++size;
    int parent = child / 2;

    while (child != 1 && nums[parent] < num) {
        nums[child] = nums[parent];
        child = parent;
        parent /= 2;
    }
    nums[child] = num;
}


#define SWAP(A, B) ((temp) = (A)), ((A) = (B)), ((B) = (temp))
int pop(void) {
    if (!size) return 0;
    
    int answer = nums[1];
    nums[1] = nums[size--];

    int parent = 1;
    int child = 2;
    int temp;

    while (size >= child) {
        
        if (size >= child + 1 && nums[child] < nums[child + 1])
            child++;
        
        if (nums[parent] >= nums[child]) break;

        SWAP(nums[parent], nums[child]);
        parent = child;
        child = parent * 2;
    }

    return answer;
}


int main(void) {
    int n, num;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num) push(num);
        else printf("%d\n", pop());
    }

    return 0;
}