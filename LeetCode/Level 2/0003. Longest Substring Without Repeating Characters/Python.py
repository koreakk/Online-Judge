class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        start = 0
        used = {}
        
        for index, char in enumerate(s):
            if char in used and used[char] >= start:
                start = used[char] + 1
            
            max_length = max(max_length, index - start + 1)
            used[char] = index
            
        return max_length