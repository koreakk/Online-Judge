#include <bits/stdc++.h>
using namespace std;

struct Point { int y, x; };

int H, W, K, board[1000][1000], dist[1000][1000][11];

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

bool inRange(int y, int x) { return y >= 0 && y < H&& x >= 0 && x < W; }

void solve() {
    cin >> H >> W >> K;

    string buf;
    for (int i = 0; i < H; ++i) {
        cin >> buf;
        for (int j = 0; j < W; ++j) {
            board[i][j] = buf[j] - '0';
        }
    }

    queue<pair<Point, int>> q;
    q.emplace(Point{ 0, 0 }, 0);

    dist[0][0][0] = 1;
    int ret = -1;

    while (!q.empty()) {
        auto [p, u] = q.front();
        auto [y, x] = p; q.pop();

        if (y == H - 1 && x == W - 1) {
            ret = dist[y][x][u];
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (!inRange(ny, nx)) {
                continue;
            }

            int nu = board[ny][nx] ? u + 1 : u;

            if (nu > K || dist[ny][nx][nu]) {
                continue;
            }

            dist[ny][nx][nu] = dist[y][x][u] + 1;
            q.emplace(Point{ ny, nx }, nu);
        }
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}