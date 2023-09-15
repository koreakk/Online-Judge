n, x = map(int, input().split())
a = list(map(int, input().split()))

print(min(a[i]+a[i+1] for i in range(n-1)) * x)