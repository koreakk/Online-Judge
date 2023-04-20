for _ in range(int(input())):
    input()
    A = list(map(int, input().split()))

    print((max(A) - min(A)) * 2)
