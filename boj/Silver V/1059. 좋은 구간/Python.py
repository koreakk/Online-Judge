def solution(L: int, S: list[int], n: int) -> int:
    if n in S :
        return 0

    min_num = max(filter(lambda x: x < n, S + [0])) + 1
    max_num = min(filter(lambda x: x > n, S)) - 1

    return (max_num - n + 1) * (n - min_num) + (max_num - n)



if __name__ == '__main__':
    L = int(input())
    S = list(map(int, input().split()))
    n = int(input())

    print(solution(L, S, n))