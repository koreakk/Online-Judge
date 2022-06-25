import collections
from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = collections.defaultdict(list)
        
        for ward in strs:
            anagrams[''.join(sorted(ward))].append(ward)
        return list(anagrams.values())


if __name__ == "__main__":
    s = Solution()
    strs = ["eat","tea","tan","ate","nat","bat"]
    result = s.groupAnagrams(strs)
    print(result)