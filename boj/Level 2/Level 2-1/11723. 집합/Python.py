from sys import stdin

S = set()

def add(x):
    S.add(x)

def remove(x):
    if x in S:
        S.remove(x)

def check(x):
    print(int(x in S))

def toggle(x):
    if x in S:
        S.remove(x)
    else:
        S.add(x)

def all():
    for x in range(1, 21):
        S.add(x)

def empty():
    S.clear()


if __name__ == '__main__':
    function_table = {
        'add': add, 'remove': remove, 'check': check, 
        'toggle': toggle, 'all': all, 'empty': empty
    }

    m = int(stdin.readline())
    for _ in range(m):
        command = stdin.readline().split()

        if len(command) == 1:
            function_table[command[0]]()
        else:
            f, x = command
            function_table[f](int(x))
