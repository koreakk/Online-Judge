n = int(input())
m = int(input())
brokenButton = set()
if m:
    brokenButton = set(input().split())

answer = abs(n - 100)
for channel in range(1000000):
    if brokenButton & set(str(channel)):
        continue

    answer = min(
        abs(channel - n) + len(str(channel)),
        answer
    )

print(answer)
