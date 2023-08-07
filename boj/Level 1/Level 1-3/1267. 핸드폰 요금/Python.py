input()
l = list(map(int, input().split()))

y = sum(map((lambda n: (n // 30 + 1) * 10), l))
m = sum(map((lambda n: (n // 60 + 1) * 15), l))

if (m < y)   : print('M %d'   % m)
elif (m > y) : print('Y %d'   % y)
else         : print('Y M %d' % m)