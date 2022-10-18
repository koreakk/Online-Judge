from sys import stdin

n, m = map(int, stdin.readline().split())
array = list(map(int, stdin.readline().split()))

sum_array = [0] * (n + 1)
for i in range(n):
    sum_array[i + 1] = sum_array[i] + array[i]

for _ in range(m):
    i, j = map(int, stdin.readline().split())
    print(sum_array[j] - sum_array[i - 1])
