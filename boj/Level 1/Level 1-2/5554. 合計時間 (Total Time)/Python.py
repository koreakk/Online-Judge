total = 0
for _ in range(4):
    total += int(input())

div, mod = divmod(total, 60)
print(div)
print(mod)