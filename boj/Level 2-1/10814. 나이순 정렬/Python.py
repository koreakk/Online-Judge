from sys import stdin

n = int(stdin.readline())
members: list[tuple[int, str]] = list()

for _ in range(n):
    age, name = stdin.readline().split()
    age = int(age)

    members.append((age, name))

members.sort(key = lambda x: x[0])
for age, name in members:
    print(age, name)