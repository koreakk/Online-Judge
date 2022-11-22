#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 10000000;

int N, M, W[10][10];

pair<int, vector<int>> dfs(int i, int visited) {
    if (visited == (1 << N) - 1) {
        int num = W[i][0];
        vector<int> ret = { i };
        return { (num ? num : INF), ret };
    }

    int num = INF;
    vector<int> ret;
    for (int j = 0; j < N; ++j) {
        if (visited & (1 << j) || !W[i][j]) { continue; }

        auto [d, r] = dfs(j, visited | (1 << j));
        d = max(W[i][j], d);

        if (num > d) {
            num = d;
            ret = r;
        }
    }

    ret.push_back(i);
    return { num, ret };
}

void solve() {
    cin >> N >> M;

    int u, v, c;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> c;
        W[u - 1][v - 1] = c;
    }

    auto [d, r] = dfs(0, 1);
    if (d == INF) { cout << "-1\n"; }
    else {
        cout << d << endl;
        for (int i = (int)r.size() - 1; i >= 0; --i) {
            cout << r[i] + 1 << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}