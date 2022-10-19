from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        results = []
        
        def dfs(start, elements):
            if len(elements) == k:
                results.append(elements)
                return
            
            for i in range(start, n + 1):           
                dfs(i + 1, elements + [i])
        
        dfs(1, [])
        return results