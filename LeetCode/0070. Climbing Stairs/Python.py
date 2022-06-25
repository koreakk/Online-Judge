class Solution:
    dp = dict()

    def climbStairs(self, n: int) -> int:
        if n <= 3:
            return n

        if n in self.dp:
            return self.dp[n]

        self.dp[n] = self.climbStairs(n - 1) + self.climbStairs(n - 2)
        return self.dp[n]