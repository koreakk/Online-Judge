def solution(n: int, m: int, nums: list[int]):
    sequence = [0] * m
    nums.sort()
    
    def F(idx: int):
        if idx == m:
            print(*sequence)
            return
        
        for i in range(n):
            sequence[idx] = nums[i]
            F(idx + 1)
    F(0)


if __name__ == '__main__':
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    solution(n, m, nums)