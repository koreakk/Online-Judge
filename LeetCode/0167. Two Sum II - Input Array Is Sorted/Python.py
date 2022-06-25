import bisect
from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for k, v in enumerate(numbers):
            expected = target - v
            # Binary Search
            i = bisect.bisect_left(numbers, expected, k + 1)
            if i < len(numbers) and numbers[i] == expected:
                return k + 1, i + 1
            
    
if __name__ == "__main__":
    numbers = [2,7,11,15]
    target = 9
    print(Solution().twoSum(numbers, target))