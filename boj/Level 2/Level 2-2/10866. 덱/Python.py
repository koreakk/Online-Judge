from sys import stdin
import collections

deque = collections.deque()

def push_front(n: int) -> None:
    deque.appendleft(n)

def push_back(n: int) -> None:
    deque.append(n)

def pop_front() -> int:
    if deque:
        return deque.popleft()
    return -1

def pop_back() -> int:
    if deque:
        return deque.pop()
    return -1

def size() -> int:
    return len(deque)

def empty() -> int:
    if deque:
        return 0
    return 1

def front() -> int:
    if deque:
        return deque[0]
    return -1

def back() -> int:
    if deque:
        return deque[-1]
    return -1


if __name__ == '__main__':
    function_table = {
        'pop_front': pop_front, 'pop_back': pop_back,
        'size': size, 'empty': empty, 'front': front,
        'back': back
    }

    push = {
        'push_front': push_front, 'push_back': push_back
    }

    n = int(stdin.readline())
    for _ in range(n):
        command = stdin.readline().split()
        
        if command[0] in push:
            push[command[0]](int(command[1]))

        else:
            print(function_table[command[0]]())