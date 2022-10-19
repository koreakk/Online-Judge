n = int(input())
lenght = len(str(n))

result = 0
start = n - (lenght * 9) if n > (lenght * 9) else 0

for i in range(start, n):
    num = sum(map(int, str(i))) + i
    if num == n:
        result = i
        break

print(result)