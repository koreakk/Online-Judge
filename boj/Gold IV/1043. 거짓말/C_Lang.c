#include <stdio.h>
#include <stdbool.h>

int N, M;
int graph[51][51];
int check[51];
int visited[51];

void dfs(int v)
{
	visited[v] = true;

	for (int i = 1; i <= N; ++i)
	{
		if (!graph[i][v])
		{
			continue;
		}

		for (int j = 1; j <= M; ++j)
		{
			if (graph[i][j] && !visited[j])
			{
				dfs(j);
			}
		}
	}
}

int solution()
{
	for (int i = 1; i <= N; ++i)
	{
		if (!check[i])
		{
			continue;
		}

		for (int j = 1; j <= M; ++j)
		{
			if (graph[i][j] && !visited[j])
			{
				dfs(j);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= M; ++i)
	{
		result += !visited[i];
	}

	return result;
}


int main()
{
	int length, num;
	scanf("%d %d", &N, &M);
	scanf("%d", &length);
	
	for (int i = 0; i < length; ++i)
	{
		scanf("%d", &num);
		check[num] = true;
	}

	for (int i = 1; i <= M; ++i)
	{
		scanf("%d", &length);

		for (int j = 0; j < length; ++j)
		{
			scanf("%d", &num);
			graph[num][i] = true;
		}
	}

	printf("%d\n", solution());
	return 0;
}