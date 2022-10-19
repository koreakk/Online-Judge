from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []

        def dfs(elements):
            if len(elements) == len(nums):
                results.append(elements[:])
                return
            
            for num in nums:
                if num in elements:
                    continue
                
                dfs(elements + [num])
         
        dfs([])
        return results