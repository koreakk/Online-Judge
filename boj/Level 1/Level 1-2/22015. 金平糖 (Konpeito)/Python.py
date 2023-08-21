a, b, c = map(int, input().split())
print((m:=max(a, b, c))-a + m-b + m-c)