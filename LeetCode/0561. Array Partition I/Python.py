from typing import List

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])

if __name__ == '__main__':
    s = Solution()
    nums = [1, 3, 2, 4]
    
    print(s.arrayPairSum(nums))