from sys import stdin

n = int(stdin.readline())
coordinates: list[tuple[int, int]] = list()

for _ in range(n):
    x, y = map(int, stdin.readline().split())
    coordinates.append((y, x))

coordinates.sort()
for y, x in coordinates:
    print(x, y)