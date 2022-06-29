def solution(n: int, m: int, nums: list[int]):
    sequence = [0] * m
    nums.sort()

    def F(idx: int, start: int, v: bool):
        if idx == m:
            print(*sequence)
            return
        
        for i in range(start, n):
            if v and sequence[idx] == nums[i]:
                continue
            
            sequence[idx] = nums[i]
            F(idx + 1, i, False)
            v = True
    F(0, 0, True)


if __name__ == '__main__':
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))

    solution(n, m, nums)