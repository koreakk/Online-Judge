#include <bits/stdc++.h>
using namespace std;

int A[100][100], D[100][100], T[10001], N, K, L;

const int nd[4][2] = { { 2, 3 }, { 3, 2 }, { 1, 0 }, { 0, 1 } };

const int dy[4] { -1, 1, 0, 0 };
const int dx[4] { 0, 0, -1, 1 };

bool inRange(int y, int x) { return y >= 0 && y < N && x >= 0 && x < N; }

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; ++i) {
        int y, x;
        cin >> y >> x;

        A[y-1][x-1] = 1;
    }

    memset(T, -1, sizeof(T));
    cin >> L;

    for (int i = 0; i < L; ++i) {
        int X; char C;
        cin >> X >> C;

        T[X] = (C == 'L') ? 0 : 1;
    }

    memset(D, -1, sizeof(D));
    D[0][0] = 3;

    int time = 0;
    int head_y = 0, head_x = 0;
    int tail_y = 0, tail_x = 0;

    for (;;) {
        ++time;
        int h_direction = D[head_y][head_x];

        head_y += dy[h_direction];
        head_x += dx[h_direction];

        if (!inRange(head_y, head_x) || D[head_y][head_x] != -1) {
            break;
        }

        if (A[head_y][head_x] == 0) {
            int t_direction = D[tail_y][tail_x];
            
            D[tail_y][tail_x] = -1;
            
            tail_y += dy[t_direction];
            tail_x += dx[t_direction];
        }

        A[head_y][head_x] = 0;
        D[head_y][head_x] = h_direction;
        
        if (T[time] != -1) { D[head_y][head_x] = nd[h_direction][T[time]]; }
    }

    cout << time << '\n';
    return 0;
}
