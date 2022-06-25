l, p = map(int, input().split())
array = map(int, input().split())

mul = l * p
answer = map(lambda x: x - mul, array)
print(*answer)
