from sys import stdin

K = int(stdin.readline())
stack = list()

for _ in range(K):
    number = int(stdin.readline())
    
    if number == 0:
        stack.pop()
    else:
        stack.append(number)

print(sum(stack))