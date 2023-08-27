d, h, m = map(int, input().split())
print(max((d*1440 + h*60 + m) - 16511, -1))