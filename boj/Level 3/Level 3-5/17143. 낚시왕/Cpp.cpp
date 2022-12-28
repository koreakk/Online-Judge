#include <bits/stdc++.h>
using namespace std;

const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

struct info { int s, d, z; };

int R, C, M;
info A[101][101], T[101][101];

tuple<int, int, int> nextMove(int y, int x, int s, int d) {
    if (d == 1 || d == 2) {
        for (s %= (R - 1) * 2; s; --s, y += dy[d - 1]) {
            if (y == 1 && d == 1) { d = 2; }
            if (y == R && d == 2) { d = 1; }
        }
    }
    else {
        for (s %= (C - 1) * 2; s; --s, x += dx[d - 1]) {
            if (x == 1 && d == 4) { d = 3; }
            if (x == C && d == 3) { d = 4; }
        }
    }

    return { y, x, d };
}

void solve() {
    cin >> R >> C >> M;

    for (int i = 0; i < M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        A[r][c] = { s, d, z };
    }

    int ret = 0;
    for (int i = 1; i <= C; ++i) {

        for (int j = 1; j <= R; ++j) {
            if (A[j][i].z) {
                ret += A[j][i].z;
                A[j][i] = { 0, 0, 0 };
                break;
            }
        }

        memset(T, 0, sizeof(T));
        for (int y = 1; y <= R; ++y) {
            for (int x = 1; x <= C; ++x) {
                auto [s, d, z] = A[y][x];
                if (!A[y][x].z) { continue; }

                auto [ny, nx, nd] = nextMove(y, x, s, d);
                if (T[ny][nx].z < z) {
                    T[ny][nx] = { s, nd, z };
                }
            }
        }
        memcpy(A, T, sizeof(T));
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
