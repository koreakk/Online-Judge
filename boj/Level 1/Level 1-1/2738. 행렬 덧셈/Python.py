n, m = map(int, input().split())
A, B = [], []

for _ in range(n):
    A.append(list(map(int, input().split())))
for _ in range(n):
    B.append(list(map(int, input().split())))

for i in range(n):
    for j in range(m):
        print(A[i][j] + B[i][j], end=' ')
    print()