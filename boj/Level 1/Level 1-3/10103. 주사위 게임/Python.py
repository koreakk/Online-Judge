p1, p2 = 100, 100
for _ in range(int(input())):
    s1, s2 = map(int, input().split())
    if (s1 < s2):
        p1 -= s2
    elif (s1 > s2):
        p2 -= s1

print(p1)
print(p2)
