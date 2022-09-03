#include <math.h>
#include <stdio.h>

#define SQRT(x)	((int)(sqrtf((float)(x))))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int dp[50001] = { 0, 1 };

int solution(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		int answer = 1e9;

		for (int j = SQRT(i); j > 0; --j)
		{
			int curr = dp[i - (j * j)] + 1;

			answer = MIN(answer, curr);
		}
		
		dp[i] = answer;
	}

	return dp[n];
}

int main()
{
	int n;
	scanf("%d", &n);

	printf("%d\n", solution(n));

	return 0;
}
