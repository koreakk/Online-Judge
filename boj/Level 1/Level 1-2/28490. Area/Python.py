ret=0
for _ in range(int(input())):
    a, b = map(int, input().split())
    ret = max(ret, a*b)
print(ret)