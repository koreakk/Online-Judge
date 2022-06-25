class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        for char in sorted(set(s)):
            suffix = s[s.index(char):]
            if set(s) == set(suffix):
                return char + self.removeDuplicateLetters(suffix.replace(char, ''))
        return ''

if __name__ == '__main__':
    S = Solution()
    result = S.removeDuplicateLetters('bcabc')
    
    print(result)