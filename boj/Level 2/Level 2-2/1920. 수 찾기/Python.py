def solution(n: int, nums: list[int], m: int, targets: list[int]) -> list[int]:
    def F(target: int) -> int:
        start, end = 0, n - 1

        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return 1
    
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        return 0
    
    nums.sort()
    return list(map(F, targets))


if __name__ == '__main__':    
    n = int(input())
    nums = list(map(int, input().split()))
    m = int(input())
    targets = list(map(int, input().split()))

    print(*solution(n, nums, m, targets), sep='\n')
