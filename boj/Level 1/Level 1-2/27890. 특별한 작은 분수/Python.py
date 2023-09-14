x, n = map(int, input().split())
for _ in range(n):
    x = (2*x)^6 if x&1 else (x//2)^6
print(x)