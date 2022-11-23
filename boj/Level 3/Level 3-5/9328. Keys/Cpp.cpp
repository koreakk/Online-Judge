#include <bits/stdc++.h>
using namespace std;

constexpr int dx[4] = { 0, 0, -1, 1 };
constexpr int dy[4] = { -1, 1, 0, 0 };

int H, W;
char A[100][100];
bool K[26], V[100][100];

bool inRange(int y, int x) { return y >= 0 && y < H && x >= 0 && x < W; }

void solve() {
    memset(A, 0, sizeof(A));
    memset(K, 0, sizeof(K));
    memset(V, 0, sizeof(V));

    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    string s; cin >> s;
    for (char k : s) {
        if (k == '0') { break; }
        K[k - 'a'] = true;
    }
    
    vector<pair<int, int>> upper[26];
    queue<pair<int, int>>  q;

    for (int y = 0; y < H; ++y) {
        if ( A[y][0]     != '*' ) { q.emplace(y,     0); }
        if ( A[y][W - 1] != '*' ) { q.emplace(y, W - 1); }
    }
    for (int x = 0; x < W; ++x) {
        if ( A[0][x]     != '*' ) { q.emplace(0,     x); }
        if ( A[H - 1][x] != '*' ) { q.emplace(H - 1, x); }
    }

    int ret = 0;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (V[y][x]) { continue; }

        V[y][x] = true;
        char k  = A[y][x];

        if (k == '$') { ++ret; }

        else if (islower(k) && !K[k - 'a']) {
            K[k - 'a'] = true;

            for (auto [ny, nx] : upper[k - 'a']) {
                q.emplace(ny, nx);
                V[ny][nx] = false;
            }
        }

        else if (isupper(k) && !K[k - 'A']) {
            upper[k - 'A'].emplace_back(y, x);
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inRange(ny, nx) || V[ny][nx] || A[ny][nx] == '*') {
                continue;
            }

            q.emplace(ny, nx);
        }
    }

    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}