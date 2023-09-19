n = int(input())
l = list(map(int, input().split())) + [0]*(5-n)

A = l[0]-l[2]
A = A*508 if A>0 else A*-108

B = l[1]-l[3]
B = B*212 if B>0 else B*-305

C = l[4]*707

print((A+B+C) * 4763)