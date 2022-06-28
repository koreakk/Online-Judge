def solution(n: int, m: int, nums: list[int]):
    sequence = [0] * m
    nums.sort()

    def F(idx: int, start: int):
        if idx == m:
            print(*sequence)
            return
        
        for i in range(start, n):
            sequence[idx] = nums[i]
            F(idx + 1, i + 1)
    F(0, 0)


if __name__ == '__main__':
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    solution(n, m, nums)