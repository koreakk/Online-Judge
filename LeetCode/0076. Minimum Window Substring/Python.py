import collections

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        counts = collections.defaultdict(int)
        required = len(t)
        for char in t:
            counts[char] += 1

        start = end = left = right = 0
        while right < len(s):
            required -= counts[s[right]] > 0
            counts[s[right]] -= 1
            right += 1

            if required: continue

            while counts[s[left]] < 0:
                counts[s[left]] += 1
                left += 1
            
            if not end or (end - start) > (right - left):
                start, end = left, right
                counts[s[left]] += 1
                left += 1
                required += 1
        return s[start:end]

if __name__ == '__main__':    
    s = "ADOBECODEBANC"
    t = "ABC"
    print(Solution().minWindow(s, t))    # BANC