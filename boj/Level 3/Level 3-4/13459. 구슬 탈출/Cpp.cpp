#include <bits/stdc++.h>
using namespace std;

constexpr int dx[4] = { 0, 0, -1, 1 };
constexpr int dy[4] = { -1, 1, 0, 0 };

int H, W;
char board[10][10];
bool visited[10][10][10][10];

struct Point { int y, x; };

pair<Point, Point> move(Point rp, Point bp, int d) {
    while (true) {
        if (board[rp.y][rp.x] == '.') {
            rp.y += dy[d], rp.x += dx[d];
        }

        if (board[bp.y][bp.x] == '.') {
            bp.y += dy[d], bp.x += dx[d];
        }

        if (board[rp.y][rp.x] != '.' && board[bp.y][bp.x] != '.') {
            if (board[rp.y][rp.x] == '#') {
                rp.y -= dy[d], rp.x -= dx[d];
            }

            if (board[bp.y][bp.x] == '#') {
                bp.y -= dy[d], bp.x -= dx[d];
            }
            return { rp, bp };
        }

        if (board[rp.y][rp.x] == '#') {
            rp.y -= dy[d], rp.x -= dx[d];

            if (rp.y == bp.y && rp.x == bp.x) {
                bp.y -= dy[d], bp.x -= dx[d];
                return { rp, bp };
            }
        }

        if (board[bp.y][bp.x] == '#') {
            bp.y -= dy[d], bp.x -= dx[d];

            if (rp.y == bp.y && rp.x == bp.x) {
                rp.y -= dy[d], rp.x -= dx[d];
                return { rp, bp };
            }
        }
    }
}

void solve() {
    cin >> H >> W;

    Point rp, bp;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                rp.y = i, rp.x = j;
                board[i][j] = '.';
            }
            else if (board[i][j] == 'B') {
                bp.y = i, bp.x = j;
                board[i][j] = '.';
            }
        }
    }

    visited[rp.y][rp.x][bp.y][bp.x] = true;
    queue<pair<Point, Point>> q;
    q.emplace(rp, bp);

    for (int i = 0; i < 10 && !q.empty(); ++i) {
        int N = (int)q.size();

        for (int j = 0; j < N; ++j) {
            auto [rp, bp] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                auto [nr, nb] = move(rp, bp, d);

                if (visited[nr.y][nr.x][nb.y][nb.x]) {
                    continue;
                }

                if (board[nb.y][nb.x] == 'O') {
                    continue;
                }

                if (board[nr.y][nr.x] == 'O') {
                    cout << "1\n";
                    return;
                }

                visited[nr.y][nr.x][nb.y][nb.x] = true;
                q.emplace(nr, nb);
            }
        }
    }

    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}