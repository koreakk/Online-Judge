def fib(n, mod):
    P = mod // 10 * 15
    
    x, y = 0, 1
    for _ in range(n % P):
        x, y = y, (x + y) % mod
    return x

if __name__ == '__main__':
    n = int(input())
    print(fib(n, 1000000))