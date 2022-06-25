from sys import stdin

N, M, B = map(int, stdin.readline().rstrip().split())
heights = []
for _ in range(N):
    heights.append(list(map(int, stdin.readline().rstrip().split())))


best_time = float('inf')

max_height = max(map(max, heights))
min_height = min(map(min, heights))

for height in range(max_height, min_height - 1, -1):
    used_blocks = 0
    time = 0
    for i in range(N):
        for j in range(M):
            diff = heights[i][j] - height
            time += -diff if diff < 0 else diff * 2
            used_blocks -= diff

    if B < used_blocks: continue
    if best_time > time:
        best_time, best_height = time, height

print(best_time, best_height)