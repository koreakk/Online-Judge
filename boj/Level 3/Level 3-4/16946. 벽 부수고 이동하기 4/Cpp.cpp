#include <bits/stdc++.h>
using namespace std;

int H, W, board[1000][1000], visited[1000][1000];

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

bool inRange(int y, int x) { return y >= 0 && y < H && x >= 0 && x < W; }

int dfs(int y, int x, int k) {
    visited[y][x] = k;

    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!inRange(ny, nx) || visited[ny][nx] || board[ny][nx]) {
            continue;
        }

        ret += dfs(ny, nx, k);
    }

    return ret;
}

void solve() {
    cin >> H >> W;

    string buf;
    for (int i = 0; i < H; ++i) {
        cin >> buf;
        for (int j = 0; j < W; ++j) {
            board[i][j] = buf[j] - '0';
        }
    }

    int k = 1;
    map<int, int> mp;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] || visited[i][j]) {
                continue;
            }

            mp[k] = dfs(i, j, k);
            ++k;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            int ret = 0;

            if (board[i][j]) {
                set<int> in;
                ++ret;

                for (int d = 0; d < 4; ++d) {
                    int y = i + dy[d];
                    int x = j + dx[d];

                    if (!inRange(y, x) || board[y][x]) {
                        continue;
                    }

                    int k = visited[y][x];
                    if (in.find(k) != in.end()) {
                        continue;
                    }

                    ret += mp[k];
                    in.insert(k);
                }
            }
            cout << ret % 10;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}