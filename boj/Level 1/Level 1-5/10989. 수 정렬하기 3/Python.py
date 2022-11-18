from sys import stdin

n = int(stdin.readline())
count = [0] * 10001

for i in range(n):
    data = int(stdin.readline())
    count[data] += 1

for i in range(1, 10001):
    for _ in range(count[i]):
        print(i, end='\n')