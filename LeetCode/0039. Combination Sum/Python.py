from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        results = []
        
        def dfs(candidates_sum, index, path):
            if candidates_sum < 0:
                return
            if candidates_sum == 0:
                results.append(path)
                return
                
            for i in range(index, len(candidates)):
                dfs(candidates_sum - candidates[i], i, path + [candidates[i]])

        dfs(target, 0, [])
        return results