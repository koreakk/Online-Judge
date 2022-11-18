from sys import stdin

fibonacciTable = [0, 1] + [0] * 100000
for i in range(2, len(fibonacciTable)):
    fibonacciTable[i] = fibonacciTable[i - 1] + fibonacciTable[i - 2]

def solution(n):
    l, r = 0, len(fibonacciTable) - 1
    
    while (l < r):
        mid = l + (r - l) // 2

        if fibonacciTable[mid] <= n:
            l = mid + 1
        else:
            r = mid

    return r - 1

if __name__ == '__main__':
    TestCase = int(stdin.readline())

    for _ in range(TestCase):
        n = int(stdin.readline())
        print(solution(n))
