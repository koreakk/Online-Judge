from sys import stdin
from collections import deque

def R():
    global isreverse
    isreverse = not isreverse


def D():
    if isreverse:
        nums.pop()
    else:
        nums.popleft()

FUNC = {'R': R, 'D': D}

T = int(stdin.readline())
for i in range(T):
    p = stdin.readline().rstrip()
    n = int(stdin.readline())
    nums = deque(eval(stdin.readline()))
    isreverse = False

    try:
        for f in p:
            FUNC[f]()
    except:
        print('error')
        continue

    if isreverse:
        nums.reverse()

    print(str(list(nums)).replace(' ', ''))
    
