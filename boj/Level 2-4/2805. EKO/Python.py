from sys import stdin


def solution(m: int, nums: list[int]) -> int:
    start, end = 0, max(nums),

    while start <= end:
        mid = start + (end - start) // 2
        length = sum(num - mid for num in nums if num > mid)

        if length >= m:
            start = mid + 1
        else:
            end = mid - 1

    return end


if __name__ == '__main__':
    n, m = map(int, stdin.readline().split())
    nums = list(map(int, stdin.readline().split()))

    print(solution(m, nums))
