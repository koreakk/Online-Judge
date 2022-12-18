#include <bits/stdc++.h>
using namespace std;
using t3 = tuple<int, int, int>;
using PQ = priority_queue<t3, vector<t3>, greater<t3>>;

constexpr int INF   = 100000000;
constexpr int dy[4] = { -1, 1, 0, 0 };
constexpr int dx[4] = { 0, 0, -1, 1 };

int H, W, A[1000][1000], V[1000][1000];

bool inRange(int y, int x) {
    return y >= 0 && y < H && x >= 0 && x < W;
}

void solve() {
    cin >> H >> W;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            V[i][j] = INF;
        }
    }

    if (A[0][0] == -1) {
        cout << "-1\n";
        return;
    }

    V[0][0] = A[0][0];

    PQ pq;
    pq.emplace(A[0][0], 0, 0);

    while (!pq.empty()) {
        auto [w, y, x] = pq.top();
        pq.pop();

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (!inRange(ny, nx) || A[ny][nx] == -1) {
                continue;
            }

            int nw = w + A[ny][nx];
            if (V[ny][nx] > nw) {
                V[ny][nx] = nw;
                pq.emplace(nw, ny, nx);
            }
        }
    }

    int ret = V[H - 1][W - 1];
    cout << (ret >= INF ? -1 : ret) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
