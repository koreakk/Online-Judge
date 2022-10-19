def solution(k: int, nums: list[int]):
    sequence = [0] * 6
    def F(idx: int, start: int):
        if idx == 6:
            print(*sequence)
            return
        
        for i in range(start, k):
            sequence[idx] = nums[i]
            F(idx + 1, i + 1)

    F(0, 0)
    print()


if __name__ == '__main__':
    while True:
        k, *nums = map(int, input().split())
        if k == 0: break

        solution(k, nums)
