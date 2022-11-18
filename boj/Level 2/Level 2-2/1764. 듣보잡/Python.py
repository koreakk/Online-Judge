from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
table = {input().rstrip() for _ in range(n)}

answer = []
for _ in range(m):
    name = input().rstrip()
    
    if name in table:
        answer.append(name)

print(len(answer), *sorted(answer), sep='\n')
    