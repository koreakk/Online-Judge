from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[0] * (i + 1) for i in range(numRows)]

        for i in range(numRows):
            for j in range(i + 1):
                if j == 0 or j == i:
                    ans[i][j] = 1
                    continue

                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]
        
        return ans
