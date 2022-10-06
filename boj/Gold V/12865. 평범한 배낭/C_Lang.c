#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX(int left, int right)
{
	return left > right ? left : right;
}

int solution(int n, int k, const int* weightInfo, int* valueInfo)
{
	const int dpSize = (k + 1) * (n + 1);
	
	int *dp = (int*)malloc(sizeof(int) * dpSize);
	memset(dp, 0, sizeof(int) * dpSize);
	
	for (int i = 0; i < n; ++i) {
		const int weight = weightInfo[i];
		const int value  = valueInfo[i];
		
		int* prev = dp + (k + 1) * i;
		int* curr = dp + (k + 1) * (i + 1);
		
		for (int j = 1; j <= k; ++j) {
			if (weight > j) {
				curr[j] = prev[j];
			} else {
				curr[j] = MAX(prev[j], value + prev[j - weight]);		
			}
		}
	}
	
	int result = dp[dpSize - 1];
	
	free(dp);
	return result;
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	int *weightInfo = (int*)malloc(sizeof(int) * n);
	int *valueInfo  = (int*)malloc(sizeof(int) * n);
	
	for (int i = 0; i < n; ++i) {
		int w, v;
		scanf("%d %d", &w, &v);
		
		weightInfo[i] = w;
		valueInfo[i]  = v;
	}
	
	printf("%d\n", solution(n, k, weightInfo, valueInfo));
	
	free(weightInfo);
	free(valueInfo);
	return 0;
}