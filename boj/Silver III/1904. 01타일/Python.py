x, y = 1, 2

n = int(input()) # 입력
for _ in range(n - 1): # n - 1번 반복
    # f(n) = f(n-1) + f(n-2)
    # n1 = x, n2 = y
    # n1, n2, (n1 + n2), ((n1 + n2) + n2), ...
    x, y = y, (x + y) % 15746 # x : n1 -> n2, y : n2 -> n3
 
print(x)