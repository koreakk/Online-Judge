class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s

        result = ''
        cycle = 2 * numRows - 2
        for i in range(numRows):
            for j in range(i, len(s), cycle):
                result += s[j]
                if i != (numRows - 1) and \
                   i != 0 and \
                   j + cycle - 2 * i < len(s):

                   result += s[j + cycle - 2 * i]
        return result

        
if __name__ == '__main__':
    s = "PAYPALISHIRING"
    numRows = 3
    print(Solution().convert(s, numRows))