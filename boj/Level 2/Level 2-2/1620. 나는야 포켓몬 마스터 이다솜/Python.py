from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
table = dict()

for i in range(1, n + 1):
    name = input().rstrip()
    table[name] = str(i)
    table[str(i)] = name

for _ in range(m):
    print(table[input().rstrip()])