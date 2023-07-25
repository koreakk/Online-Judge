import sys

input = sys.stdin.readline

for _ in range(3):
    s = sum(int(input()) for _ in range(int(input())))
    print('0' if s==0 else '+' if s>0 else '-')