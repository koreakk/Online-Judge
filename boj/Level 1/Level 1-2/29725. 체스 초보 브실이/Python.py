s = {'.' :  0, 'K' :  0, 'k' :  0,
     'P' :  1, 'p' : -1, 'N' :  3,
     'n' : -3, 'B' :  3, 'b' : -3,
     'R' :  5, 'r' : -5, 'Q' :  9, 'q' : -9}

ret = 0
for _ in range(8):
    ret += sum(s[x] for x in input())

print(ret)