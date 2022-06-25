from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) <= 2:
            return max(nums)

        x, y = nums[0], max(nums[0], nums[1])

        for i in range(2, len(nums)):
            x, y = y, max(y, x + nums[i])
        
        return y


if __name__ == '__main__':
    nums = [2, 7, 9, 3, 1]
    print(Solution().rob(nums))