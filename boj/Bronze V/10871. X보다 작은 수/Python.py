n, x = map(int, input().split())
array = map(int, input().split())

answer = filter(lambda num: x > num, array)
print(*answer)