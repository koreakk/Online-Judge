from sys import stdin

stack = []

def pop() -> int:
    if not stack:
        return -1
    
    return stack.pop()

def size() -> int:
    return len(stack)

def empty() -> int:
    if stack:
        return 0
    return 1

def top() -> int:
    if stack:
        return stack[-1]
    return -1

def push(n: int) -> None:
    stack.append(n)


if __name__ == '__main__':
    function_table = {
        'pop': pop, 'size': size,
        'empty': empty, 'top': top
    }

    n = int(stdin.readline())

    for _ in range(n):
        command = stdin.readline().split()
        
        if command[0] == 'push':
            push(int(command[1]))
 
        else:
            print(function_table[command[0]]())