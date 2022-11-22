#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 10000000;

int N, W[10][10];

int dfs(int i, int visited) {
    if (visited == (1 << N) - 1) {
        int ret = W[i][0];
        return ret ? ret : INF;
    }

    int ret = INF;
    for (int j = 0; j < N; ++j) {
        if (visited & (1 << j) || !W[i][j]) { continue; }

        ret = min(ret, W[i][j] + dfs(j, visited | (1 << j)));
    }
    
    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    cout << dfs(0, 1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}