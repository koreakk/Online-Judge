n = int(input())
minMax = lambda x: (min(x), max(x))
min_num, max_num = minMax(list(map(int, input().split())))

print(min_num, max_num)