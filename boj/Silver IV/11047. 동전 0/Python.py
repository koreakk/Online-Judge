a, b = map(int, input().split())
d = [int(input()) for _ in range(a)]

c = 0
for i in range(1, a+1):
  c += b // d[a-i]
  b %= d[a-i]

print(c)