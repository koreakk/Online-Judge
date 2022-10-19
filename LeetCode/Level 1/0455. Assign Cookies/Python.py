from typing import List

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i = j = 0
        while i < len(g) and j < len(s):
            if g[i] <= s[j]:
                i += 1
                j += 1
            else:
                j += 1
        return i

if __name__ == '__main__':
    g = [1,2,3]
    s = [1,1]
    print(Solution().findContentChildren(g, s))