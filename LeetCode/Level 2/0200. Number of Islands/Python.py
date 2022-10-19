from typing import List

class Solution:
    def _dfs(self, i: int, j: int):
        if i < 0 or i >= self.max_i or \
           j < 0 or j >= self.max_j or \
           self.grid[i][j] == '0':
            return
        else:
            self.grid[i][j] = '0'
            self._dfs(i + 1, j)
            self._dfs(i - 1, j)
            self._dfs(i, j + 1)
            self._dfs(i, j - 1)
         
    def numIslands(self, grid: List[List[str]]) -> int:
        self.grid = grid
        self.max_i = len(grid)
        self.max_j = len(grid[0])
        
        count = 0
        for i in range(self.max_i):
            for j in range(self.max_j):
                if self.grid[i][j] == '1':
                    self._dfs(i, j)
                    count += 1
        return count

if __name__ == '__main__': 
    grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]

    print(Solution().numIslands(grid))