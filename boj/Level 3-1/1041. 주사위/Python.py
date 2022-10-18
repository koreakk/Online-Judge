def solution(n: int, nums: list[int]) -> int:
    if n == 1:
        return sum(sorted(nums)[:5])
    
    min_nums = []
    for i in range(3):
        min_nums.append(
            min(nums[i], nums[5 - i])
        )
    
    num1, num2, num3 = sorted(min_nums)
    answer = (5 * (n ** 2) - 8 * n + 4) * num1
    answer += (8 * n - 8) * num2
    answer += 4 * num3
    return answer


if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))

    print(solution(n, nums))
