def solution(n: int, nums: list[int], s: int):
    for i in range(n):
        idx = i

        for j in range(i + 1, n):
            if j > i + s:
               break

            if nums[idx] < nums[j]:
                idx = j

        s -= idx - i  
        max_num = nums[idx]

        for k in range(idx, i, -1):
            nums[k] = nums[k - 1]
        nums[i] = max_num

        if s <= 0: break

    print(*nums)

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    s = int(input())

    solution(n, nums, s)
