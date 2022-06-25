A, B, C = map(int,input().split())

print((A // (C - B) + 1) if B < C else -1)
