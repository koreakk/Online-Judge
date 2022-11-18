#include <iostream>
#include <algorithm>
using namespace std;

int r, c, v[26];
char a[22][22];

int dfs(int x, int y) {
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    v[a[y][x] - 'A'] = 1;
    int res = 0;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= c || ny < 0 || ny >= r) {
            continue;
        }

        if (v[a[ny][nx] - 'A'] != 1) {
            res = max(res, dfs(nx, ny));
        }
    }

    v[a[y][x] - 'A'] = 0;
    return res + 1;
}

void solve() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        cin >> a[i];
    cout << dfs(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}