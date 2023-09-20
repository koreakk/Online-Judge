input()
A = list(map(int, input().split()))
B = list(map(int, input().split()))

print(sum(a<=b for a, b in zip(A, B)))