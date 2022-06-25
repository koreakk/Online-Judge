import collections

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = collections.defaultdict(int)
        most_common = 0
        left = right = 0
        while right < len(s):
            counts[s[right]] += 1
            most_common = max(most_common, counts[s[right]])
            right += 1

            if (right - left - most_common) > k:
                counts[s[left]] -= 1
                left += 1
        return right - left

if __name__ == '__main__':
    s = "AABABBA"
    k = 1
    print(Solution().characterReplacement(s, k))    # 4