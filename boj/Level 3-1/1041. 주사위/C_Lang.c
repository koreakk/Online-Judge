#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	size_t num1 = *(size_t*)a;
	size_t num2 = *(size_t*)b;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;
	
	return 0;
}

#define MAX(A, B)		((A) > (B)) ? (A) : (B)
#define MIN(A, B)		((A) < (B)) ? (A) : (B)

size_t solution(size_t n, size_t* nums) {
	if (n == 1) {
		size_t sum = 0;
		size_t max = 0;

		for (int i = 0; i < 6; i++) {
			sum += nums[i];
			max = MAX(max, nums[i]);
		}

		return sum - max;
	}

	size_t answer;
	size_t min_nums[3];

	for (int i = 0; i < 3; i++) {
		min_nums[i] = MIN(nums[i], nums[5 - i]);
	}

	qsort(min_nums, 3, sizeof(size_t), compare);
	answer = (5 * (n * n) - 8 * n + 4) * min_nums[0];
	answer += (8 * n - 8) * min_nums[1];
	answer += 4 * min_nums[2];

	return answer;
}


int main(void) {
	size_t n;
	size_t nums[6];
	
	scanf("%zu", &n);
	for (int i = 0; i < 6; i++)
		scanf("%zu", nums + i);
	
	printf("%zu\n", solution(n, nums));
	return 0;
}