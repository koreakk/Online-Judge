class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        xor = x ^ y
        count = 0
        while xor:
            xor &= xor - 1
            count += 1
        return count

if __name__ == "__main__":
    x = 1    # 0001
    y = 4    # 1000
    print(Solution().hammingDistance(x, y))