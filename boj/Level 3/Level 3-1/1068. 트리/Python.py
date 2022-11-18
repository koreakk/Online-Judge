from collections import defaultdict


def solution(data: list[int], delete_node: int) -> int:
    tree = defaultdict(list)
    root = 0
    for i, p in enumerate(data):
        if p == -1:
            root = i
        tree[p].append(i)

    def dfs(node: int):
        if node == delete_node:
            return 0

        if node not in tree:
            return 1
        
        reaf_cnt = 0
        for next_node in tree[node]:
            reaf_cnt += dfs(next_node)

        return max(1, reaf_cnt)

    return dfs(root)


if __name__ == '__main__':
    n = int(input())
    data = list(map(int, input().split()))
    delete_node = int(input())

    print(solution(data, delete_node))