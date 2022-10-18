def solution(nums: list[int]) -> int:
    def F(n: int) -> int:
        if n < 2:
            return 0
        
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return 0
        return 1
    
    return sum(map(F, nums))


if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))

    print(solution(nums))