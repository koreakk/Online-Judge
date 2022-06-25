def isRightTriangle(a, b, c):
    # a^2 + b^2 = c^2
    return (a*a) + (b*b) == (c*c)

while True:
    a, b, c = sorted(map(int, input().split()))

    if not (a or b or c): break

    print('right' if isRightTriangle(a, b, c) else 'wrong')