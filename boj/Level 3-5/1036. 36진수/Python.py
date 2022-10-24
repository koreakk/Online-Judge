def conversion(num, base):
    answer = ''
    while num:
        x = num % base
        if (x < 10):
            x = str(x)
        else:
            x = chr(x - 10 + ord('A'))
        answer = x + answer
        num //= base
    return answer if answer else '0'

BASE = 36
INT  = lambda x: int(x, BASE)
Z    = INT('Z')

N    = int(input())
NUMS = [input() for _ in range(N)]
K    = int(input())

value = [0] * BASE
for num in NUMS:
    for digit, idx in zip(num, range(len(num) - 1, -1, -1)):
        value[INT(digit)] += BASE ** idx

diff   = sorted(range(BASE), key=lambda x: (value[x] * (Z - x), x))
answer = sum(value[x] * x if i < BASE - K 
                else value[x] * Z for i, x in enumerate(diff))

print(conversion(answer, BASE))