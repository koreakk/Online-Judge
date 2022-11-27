#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int H, W, board[1000][1000];
int V[1000][1000];

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };

bool compare(const pii& l, const pii& r) {
    const auto& [ly, lx] = l;
    const auto& [ry, rx] = r;

    return board[ly][lx] > board[ry][rx];
}

bool dfs(int y, int x) {
    V[y][x] = 1;

    if (board[y][x] == 0) {
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if ((ny < 0 || ny >= H || nx < 0 || nx >= W) || board[ny][nx] == -1) {
            continue;
        }

        if (board[ny][nx] < board[y][x] - 1) {
            return false;
        }

        if (V[ny][nx] == 1 || board[ny][nx] != board[y][x] - 1) {
            continue;
        }

        if (dfs(ny, nx) == false) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> H >> W;

    vector<pii> info;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> board[i][j];
            if (board[i][j] != -1 && board[i][j] != 0) {
                info.emplace_back(i, j);
            }
        }
    }
    sort(info.begin(), info.end(), compare);

    int ret = 0;
    for (auto [y, x] : info) {
        if (V[y][x] != 1) {
            if (dfs(y, x) == false) {
                cout << "-1\n";
                return;
            }
            ++ret;
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