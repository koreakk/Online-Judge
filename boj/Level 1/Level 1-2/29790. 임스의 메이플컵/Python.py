n, u, l = map(int, input().split())
if n < 1000:
    print('Bad')
elif u < 8000 and l < 260:
    print('Good')
else:
    print('Very Good')