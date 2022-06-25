A, B, V = map(int, input().split())
V = (V - A) - 1 
print((V // (A - B)) + 2)