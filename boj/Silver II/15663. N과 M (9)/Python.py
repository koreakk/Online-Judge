def solution(n: int, m: int, nums: list[int]):
    sequence = [0] * m
    visited = [False] * (n + 1)
    nums.sort()
    
    def F(idx: int, v: bool):
        if idx == m:
            print(*sequence)
            return
        
        for i in range(n):
            if visited[i]:
                continue
            if v and sequence[idx] == nums[i]:
                continue
            
            sequence[idx] = nums[i]
            visited[i] = True

            F(idx + 1, False)
            visited[i] = False
            v = True
    F(0, True)


if __name__ == '__main__':
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))

    solution(n, m, nums)