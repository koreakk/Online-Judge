#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int solution(const int* array, int length)
{
    int* dp = (int*)malloc(sizeof(int) * length);
    memset(dp, 0, sizeof(int) * length);

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (array[j] < array[i] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        }
    }

    int answer = 0;
    for (int i = 0; i < length; ++i)
        answer = MAX(answer, dp[i]);

    free(dp);
    return answer + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int* array = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i)
        scanf("%d", array + i);

    printf("%d\n", solution(array, n));

    free(array);
    return 0;
}