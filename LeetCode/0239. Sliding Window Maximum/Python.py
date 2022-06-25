import collections
from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        results = []
        queue = collections.deque()
        for i, v in enumerate(nums):
            while queue and nums[queue[-1]] < v:
                queue.pop()
            queue.append(i)

            if (i - k) >= queue[0]:
                queue.popleft()
                
            if (i + 1) >= k:
                results.append(nums[queue[0]])

        return results

if __name__ == '__main__':
    nums = [1,3,-1,-3,5,3,6,7]
    k = 3
    print(Solution().maxSlidingWindow(nums, k))