class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            n &= n - 1
            count += 1
        return count

if __name__ == '__main__':
    n = 4294967293    # 11111111111111111111111111111101
    print(Solution().hammingWeight(n))    # 31
    # The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.