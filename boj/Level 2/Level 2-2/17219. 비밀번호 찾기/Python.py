from sys import stdin

n, m = map(int, stdin.readline().split())

info = {}
for _ in range(n):
    user_id, password = stdin.readline().split()
    info[user_id] = password

for _ in range(m):
    user_id = stdin.readline().rstrip()
    print(info[user_id])
