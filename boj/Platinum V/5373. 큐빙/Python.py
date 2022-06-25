class Cube:
    def __init__(self):
        self.red = [
            ['r', 'r', 'r'],
            ['r', 'r', 'r'],
            ['r', 'r', 'r']
        ]

        self.blue = [
            ['b', 'b', 'b'],
            ['b', 'b', 'b'],
            ['b', 'b', 'b']
        ]

        self.orange = [
            ['o', 'o', 'o'],
            ['o', 'o', 'o'],
            ['o', 'o', 'o']
        ]

        self.green = [
            ['g', 'g', 'g'],
            ['g', 'g', 'g'],
            ['g', 'g', 'g']
        ]

        self.white = [
            ['w', 'w', 'w'],
            ['w', 'w', 'w'],
            ['w', 'w', 'w']
        ]

        self.yellow = [
            ['y', 'y', 'y'],
            ['y', 'y', 'y'],
            ['y', 'y', 'y']
        ]

    def U(self, rotate):
        if rotate == '+': # white 시계 방향 
            self.white = [[self.white[j][i] for j in range(3)][::-1] for i in range(3)]
            self.red[0], self.blue[0], self.orange[0], self.green[0] = self.blue[0], self.orange[0], self.green[0], self.red[0]

        elif rotate == '-': # white 반시계 방향
            self.white = [[self.white[j][i] for j in range(3)] for i in range(2, -1, -1)]
            self.blue[0], self.orange[0], self.green[0], self.red[0] = self.red[0], self.blue[0], self.orange[0], self.green[0]
    
    def D(self, rotate):
        if rotate == '+': # yellow 시계 방향
            self.yellow = [[self.yellow[j][i] for j in range(3)][::-1] for i in range(3)]
            self.blue[2], self.orange[2], self.green[2], self.red[2] = self.red[2], self.blue[2], self.orange[2], self.green[2]
       
        elif rotate == '-': # yellow 반시계 방향
            self.yellow = [[self.yellow[j][i] for j in range(3)] for i in range(2, -1, -1)]
            self.red[2], self.blue[2], self.orange[2], self.green[2] = self.blue[2], self.orange[2], self.green[2], self.red[2]

    def R(self, rotate):
        if rotate == '+': # blue 시계 방향
            self.blue = [[self.blue[j][i] for j in range(3)][::-1] for i in range(3)]
            self.orange[0][0], self.orange[2][0] = self.orange[2][0], self.orange[0][0]
            for i in range(3):
                self.red[i][2], self.yellow[i][2], self.orange[i][0], self.white[i][2] = self.yellow[i][2], self.orange[i][0], self.white[i][2], self.red[i][2]
            self.orange[0][0], self.orange[2][0] = self.orange[2][0], self.orange[0][0]

        elif rotate == '-': # blue 반시계 방향
            self.blue = [[self.blue[j][i] for j in range(3)] for i in range(2, -1, -1)]
            self.orange[0][0], self.orange[2][0] = self.orange[2][0], self.orange[0][0]
            for i in range(3):
                self.yellow[i][2], self.orange[i][0], self.white[i][2], self.red[i][2] = self.red[i][2], self.yellow[i][2], self.orange[i][0], self.white[i][2]
            self.orange[0][0], self.orange[2][0] = self.orange[2][0], self.orange[0][0]
                
    def L(self, rotate):
        if rotate == '+': # green 시계 방향
            self.green = [[self.green[j][i] for j in range(3)][::-1] for i in range(3)]
            self.orange[0][2], self.orange[2][2] = self.orange[2][2], self.orange[0][2]
            for i in range(3):
                self.yellow[i][0], self.orange[i][2], self.white[i][0], self.red[i][0] = self.red[i][0], self.yellow[i][0], self.orange[i][2], self.white[i][0]
            self.orange[0][2], self.orange[2][2] = self.orange[2][2], self.orange[0][2]
            
        elif rotate == '-': # green 반시계 방향
            self.green = [[self.green[j][i] for j in range(3)] for i in range(2, -1, -1)]
            self.orange[0][2], self.orange[2][2] = self.orange[2][2], self.orange[0][2]
            for i in range(3):
                self.red[i][0], self.yellow[i][0], self.orange[i][2], self.white[i][0] = self.yellow[i][0], self.orange[i][2], self.white[i][0], self.red[i][0]
            self.orange[0][2], self.orange[2][2] = self.orange[2][2], self.orange[0][2]
    
    def F(self, rotate):
        if rotate == '+': #red 시계 방향
            self.red = [[self.red[j][i] for j in range(3)][::-1] for i in range(3)]
            self.yellow[0][0], self.yellow[0][2] = self.yellow[0][2], self.yellow[0][0]
            self.green[0][2], self.green[2][2] = self.green[2][2], self.green[0][2]
            for i in range(3):
                self.blue[i][0], self.yellow[0][i], self.green[i][2], self.white[2][i] = self.white[2][i], self.blue[i][0], self.yellow[0][i], self.green[i][2]
            self.yellow[0][0], self.yellow[0][2] = self.yellow[0][2], self.yellow[0][0]
            self.green[0][2], self.green[2][2] = self.green[2][2], self.green[0][2]

        elif rotate == '-': # red 반시계 방향
            self.red = [[self.red[j][i] for j in range(3)] for i in range(2, -1, -1)]
            self.yellow[0][0], self.yellow[0][2] = self.yellow[0][2], self.yellow[0][0]
            self.green[0][2], self.green[2][2] = self.green[2][2], self.green[0][2]
            for i in range(3):
                self.white[2][i], self.blue[i][0], self.yellow[0][i], self.green[i][2] = self.blue[i][0], self.yellow[0][i], self.green[i][2], self.white[2][i]
            self.yellow[0][0], self.yellow[0][2] = self.yellow[0][2], self.yellow[0][0]
            self.green[0][2], self.green[2][2] = self.green[2][2], self.green[0][2]
    
    def B(self, rotate):
        if rotate == '+': # orange 시게 방향
            self.orange = [[self.orange[j][i] for j in range(3)][::-1] for i in range(3)]
            self.yellow[2][0], self.yellow[2][2] = self.yellow[2][2], self.yellow[2][0]
            self.green[0][0], self.green[2][0] = self.green[2][0], self.green[0][0]
            for i in range(3):
                self.white[0][i], self.blue[i][2], self.yellow[2][i], self.green[i][0] = self.blue[i][2], self.yellow[2][i], self.green[i][0], self.white[0][i]
            self.yellow[2][0], self.yellow[2][2] = self.yellow[2][2], self.yellow[2][0]
            self.green[0][0], self.green[2][0] = self.green[2][0], self.green[0][0]

        elif rotate == '-': # orange 반시계 방향
            self.orange = [[self.orange[j][i] for j in range(3)] for i in range(2, -1, -1)]
            self.yellow[2][0], self.yellow[2][2] = self.yellow[2][2], self.yellow[2][0]
            self.green[0][0], self.green[2][0] = self.green[2][0], self.green[0][0]
            for i in range(3):
                self.blue[i][2], self.yellow[2][i], self.green[i][0], self.white[0][i] = self.white[0][i], self.blue[i][2], self.yellow[2][i], self.green[i][0]
            self.yellow[2][0], self.yellow[2][2] = self.yellow[2][2], self.yellow[2][0]
            self.green[0][0], self.green[2][0] = self.green[2][0], self.green[0][0]


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        cube = Cube()

        n = int(input())
        movelist = list(input().split())

        for pos, rotate in movelist:
            if pos == 'U':      # 윗면
                cube.U(rotate)
            elif pos == 'D':    # 아랫면
                cube.D(rotate)
            elif pos == 'R':    # 오른쪽면
                cube.R(rotate)
            elif pos == 'L':    # 왼쪽면
                cube.L(rotate)
            elif pos == 'F':    # 앞면
                cube.F(rotate)
            elif pos == 'B':    # 뒷면
                cube.B(rotate)

        for x in cube.white:
            print(''.join(x))