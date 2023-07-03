A = sum(i * int(input()) for i in range(3, 0, -1))
B = sum(i * int(input()) for i in range(3, 0, -1))

if   (A > B): print('A')
elif (A < B): print('B')
else        : print('T')