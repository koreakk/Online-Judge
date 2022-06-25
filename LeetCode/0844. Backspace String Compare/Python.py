class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def build(s: str) -> str:
            ans = []
            for x in s:
                if x != '#':
                    ans.append(x)
                elif ans:
                    ans.pop()
            return ''.join(ans)
        return build(s) == build(t)

if __name__ == '__main__':
    s = "ab#c"
    t = "ad#c"
    print(Solution().backspaceCompare(s, t))