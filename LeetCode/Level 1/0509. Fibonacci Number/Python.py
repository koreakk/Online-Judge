class Solution:
    def fib(self, n: int) -> int:
        x, y = 0, 1
        for i in range(n):
            x, y = y, x + y
        return x

if __name__ == '__main__':
    n = 30
    print(Solution().fib(n) % 1000000)