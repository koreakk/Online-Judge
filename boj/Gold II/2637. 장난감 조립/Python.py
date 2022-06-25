from collections import defaultdict


def dfs(x: int) -> defaultdict[int, int]:
    if not graph[x]:             # x가 기본부품인 경우 처리
        dp[x][x] = 1

    elif not dp[x]:
        for y in graph[x]:
            k = graph[x][y]      # x를 만드는데 필요한 y 개수

            y_parts = dfs(y)     # y를 만들기위한 중간 부품 혹은 기본 부품

            for y_part, num in y_parts.items():
                dp[x][y_part] += num * k

    return dp[x]


if __name__ == '__main__':
    n = int(input())
    m = int(input())
    graph = [{} for _ in range(n + 1)]
    
    for _ in range(m):
        x, y, k = map(int, input().split())
        graph[x][y] = k
    
    dp = [defaultdict(int) for _ in range(n + 1)]
    
    result = dfs(n)
    for i in sorted(result):
        print(i, result[i])
