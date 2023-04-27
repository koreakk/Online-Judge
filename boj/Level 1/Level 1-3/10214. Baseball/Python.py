for _ in range(int(input())):
    n = 0
    for _ in range(9):
        y, k = map(int, input().split())
        n += y - k

    if (n > 0):
        print("Yonsei")
    elif (n < 0):
        print("Korea")
    else:
        print("Draw")
