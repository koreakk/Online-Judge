from decimal import Decimal, getcontext
getcontext().prec = 10000

a, b = map(Decimal, input().split())
print(f'{a ** b:f}')
