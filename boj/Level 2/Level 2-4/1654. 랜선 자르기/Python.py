from sys import stdin

def solution(n: int, lans: list[int]) -> int:
    start, end = 1, max(lans)

    while start <= end:
        mid = start + (end - start) // 2
        cnt = sum(lan // mid for lan in lans)

        if cnt < n:
            end = mid - 1
        else:
            start = mid + 1
    return end


if __name__ == '__main__':
    k, n = map(int, stdin.readline().split())
    lans = [int(stdin.readline()) for _ in range(k)]

    print(solution(n, lans))
