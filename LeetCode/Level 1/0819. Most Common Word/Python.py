import collections
from typing import List

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        wards = collections.defaultdict(int)
        ward = ''
        for c in paragraph:
            if c.isalnum():
                ward += c.lower()
            else:
                if ward not in banned and ward:
                    wards[ward] += 1
                ward = ''
        if ward:
            wards[ward] += 1
        
        return max(wards, key=wards.get)