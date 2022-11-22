#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 10000000;

int N, W[16][16], dp[16][1 << 16];

int dfs(int i, int visited) {
    if (dp[i][visited]) {
        return dp[i][visited];
    }

    if (visited == (1 << N) - 1) {
        int ret = W[i][0];
        dp[i][visited] = ret ? ret : INF;
        return dp[i][visited];
    }

    int ret = INF;
    for (int j = 0; j < N; ++j) {
        if (visited & (1 << j) || !W[i][j]) { continue; }

        ret = min(ret, W[i][j] + dfs(j, visited | (1 << j)));
    }
    
    dp[i][visited] = ret;
    return dp[i][visited];
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