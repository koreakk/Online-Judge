unique_nums = map(int, input().split())

print(sum(map(lambda x: pow(x, 2), unique_nums)) % 10)