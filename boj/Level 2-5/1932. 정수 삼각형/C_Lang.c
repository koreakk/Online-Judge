#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int array[501][501];

int MAX(int left, int right)
{
    return left > right ? left : right;
}

int solution(int n)
{
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            array[i][j] += MAX(array[i + 1][j], array[i + 1][j + 1]);
        }
    }

    return array[0][0];
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("%d\n", solution(n));
}