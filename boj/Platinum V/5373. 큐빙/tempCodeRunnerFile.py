def init(color: str) -> list[list[str]]:
    return [[color] * 3 for _ in range(3)]


def rotated(side: list[list[str]], left: bool) -> list[list[str]]:
    if left:
        return [[side[j][i] for j in range(3)]\
                    for i in range(2, -1, -1)]
    else:
        return [[side[j][i] for j in range(2, -1, -1)]\
                    for i in range(3)]


def U(rotate: str):
    if rotated == '+': 
        w[:] = rotated(w, False)
        r[0], b[0], o[0], g[0] = \
            b[0], o[0], g[0], r[0]

    else:
        w[:] = rotated(w, True)
        b[0], o[0], g[0], r[0] = \
            r[0], b[0], o[0], g[0]


def D(rotate: str):
    if rotated == '+':
        y[:] = rotated(y, False)
        b[2], o[2], g[2], r[2] = \
            r[2], b[2], o[2], g[2]
    
    else:
        y[:] = rotated(y, True)
        r[2], b[2], o[2], g[2] = \
            b[2], o[2], g[2], r[2]


def R(rotate: str):
    if rotate == '+':
        b[:] = rotated(b, False)
        o[0][0], o[2][0] = o[2][0], o[0][0]
        for i in range(3):
            r[i][2], y[i][2], o[i][0], w[i][2] = \
                y[i][2], o[i][0], w[i][2], r[i][2]

        o[0][0], o[2][0] = o[2][0], o[0][0]

    else:
        b[:] = rotated(b, True)
        o[0][0], o[2][0] = o[2][0], o[0][0]
        for i in range(3):
            y[i][2], o[i][0], w[i][2], r[i][2] = \
                r[i][2], y[i][2], o[i][0], w[i][2]

        o[0][0], o[2][0] = o[2][0], o[0][0]
            

def L(rotate: str):
    if rotate == '+':
        g[:] = rotated(g, False)
        o[0][2], o[2][2] = o[2][2], o[0][2]
        for i in range(3):
            y[i][0], o[i][2], w[i][0], r[i][0] = \
                r[i][0], y[i][0], o[i][2], w[i][0]

        o[0][2], o[2][2] = o[2][2], o[0][2]

    else:
        g[:] = rotated(g, True)
        o[0][2], o[2][2] = o[2][2], o[0][2]
        for i in range(3):
            r[i][0], y[i][0], o[i][2], w[i][0] = \
                y[i][0], o[i][2], w[i][0], r[i][0]

        o[0][2], o[2][2] = o[2][2], o[0][2]


def F(rotate: str):
    if rotate == '+':
        r[:] = rotated(r, False)
        y[0][0], y[0][2] = y[0][2], y[0][0]
        g[0][2], g[2][2] = g[2][2], g[0][2]
        for i in range(3):
            b[i][0], y[0][i], g[i][2], w[2][i] = \
                w[2][i], b[i][0], y[0][i], g[i][2]

        y[0][0], y[0][2] = y[0][2], y[0][0]
        g[0][2], g[2][2] = g[2][2], g[0][2]

    else:
        r[:] = rotated(r, True)
        y[0][0], y[0][2] = y[0][2], y[0][0]
        g[0][2], g[2][2] = g[2][2], g[0][2]
        for i in range(3):
            w[2][i], b[i][0], y[0][i], g[i][2] = \
                b[i][0], y[0][i], g[i][2], w[2][i]

        y[0][0], y[0][2] = y[0][2], y[0][0]
        g[0][2], g[2][2] = g[2][2], g[0][2]


def B(rotate: str):
    if rotate == '+':
        o[:] = rotated(o, True)
        y[2][0], y[2][2] = y[2][2], y[2][0]
        g[0][0], g[2][0] = g[2][0], g[0][0]
        for i in range(3):
            w[0][i], b[i][2], y[2][i], g[i][0] = \
                b[i][2], y[2][i], g[i][0], w[0][i]

        y[2][0], y[2][2] = y[2][2], y[2][0]
        g[0][0], g[2][0] = g[2][0], g[0][0]

    else:
        o[:] = rotated(o, False)
        y[2][0], y[2][2] = y[2][2], y[2][0]
        g[0][0], g[2][0] = g[2][0], g[0][0]
        for i in range(3):
            b[i][2], y[2][i], g[i][0], w[0][i] = \
                w[0][i], b[i][2], y[2][i], g[i][0]

        y[2][0], y[2][2] = y[2][2], y[2][0]
        g[0][0], g[2][0] = g[2][0], g[0][0]



T = int(input())
for _ in range(T):
    r, b, o, g, w, y = map(init, 'rbogwy')

    move_function = {
        'U': U, 'D': D, 'R': R,
        'L': L, 'F': F, 'B': B
    }

    n = int(input())
    move_data = input().split()

    for p, rotate in move_data:
        move_function[p](rotate)

    print(*map(' '.join, w), sep='\n')