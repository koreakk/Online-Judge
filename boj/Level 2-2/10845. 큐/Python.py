from sys import stdin
from collections import deque

queue = deque()

def push(n: int) -> None:
    queue.append(n)

def pop() -> int:
    if not queue:
        return -1
    
    return queue.popleft()

def size() -> int:
    return len(queue)

def empty() -> int:
    if queue:
        return 0
    return 1

def front() -> int:
    if queue:
        return queue[0]
    return -1

def back() -> int:
    if queue:
        return queue[-1]
    return -1


if __name__ == '__main__':
    function_table = {
        'pop': pop, 'size': size,
        'empty': empty, 'front': front,
        'back': back
    }

    n = int(stdin.readline())
    for _ in range(n):
        command = stdin.readline().split()
        
        if command[0] == 'push':
            push(int(command[1]))
 
        else:
            print(function_table[command[0]]())





        
        