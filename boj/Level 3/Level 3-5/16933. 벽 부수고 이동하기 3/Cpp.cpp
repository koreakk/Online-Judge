#include <bits/stdc++.h>
using namespace std;

struct Point { int y, x; };

int H, W, K, board[1000][1000], visited[1000][1000][11];

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

bool inRange(int y, int x) { return y >= 0 && y < H && x >= 0 && x < W; }

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

    visited[0][0][0] = 1;
    int ret = -1;

    for (int count = 1; !q.empty() && ret == -1; ++count) {
        int N = (int)q.size();

        for (int i = 0; i < N; ++i) {
            auto [p, u] = q.front();
            auto [y, x] = p;q.pop();

            if (visited[y][x][u] == -1) {
                visited[y][x][u] = 1;
                q.emplace(Point{ y, x }, u);
                continue;
            }

            if (y == H - 1 && x == W - 1) {
                ret = count;
                break;
            }

            for (int d = 0; d < 4; ++d) {
                int ny = dy[d] + y;
                int nx = dx[d] + x;

                if (!inRange(ny, nx)) {
                    continue;
                }

                int nu = board[ny][nx] ? u + 1 : u;

                if (nu > K || visited[ny][nx][nu]) {
                    continue;
                }

                visited[ny][nx][nu] = (!board[ny][nx] || count % 2) ? 1 : -1;
                q.emplace(Point{ ny, nx }, nu);
            }
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