#include <bits/stdc++.h>
using namespace std;

constexpr int block[4][3][2] = {
    { { 0, 0 }, { 1, 0 }, { 0,  1 } },
    { { 0, 0 }, { 1, 0 }, { 1,  1 } },
    { { 0, 0 }, { 0, 1 }, { 1,  1 } },
    { { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

int H, W, board[20][20];

bool inRange(int y, int x) { return y >= 0 && y < H && x >= 0 && x < W; }

bool setBlock(int y, int x, int type, int o) {
    bool ok = true;

    for (int i = 0; i < 3; ++i) {
        int ny = y + block[type][i][0];
        int nx = x + block[type][i][1];

        if (!inRange(ny, nx) || (board[ny][nx] += o) > 1) {
            ok = false;
        }
    }

    return ok;
}

int dfs() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j]) { continue; }

            int ret = 0;
            for (int t = 0; t < 4; ++t) {
                if (setBlock(i, j, t, 1)) {
                    ret += dfs();
                }
                setBlock(i, j, t, -1);
            }
            return ret;
        }
    }

    return 1;
}

void solve() {
    memset(board, 0, sizeof(board));

    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c; cin >> c;
            if (c == '#') {
                board[i][j] = 1;
            }
        }
    }

    cout << dfs() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}