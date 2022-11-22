#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 10000000;

int N, W[20][20], dp[20][1 << 20][2];

int dfs(int i, int visited) {
    if (dp[i][visited][0]) {
        return dp[i][visited][0];
    }

    int ret = 0;
    int nxt = -1;
    for (int j = 0; j < N; ++j) {
        if (visited & (1 << j) || !W[i][j]) { continue; }

        int x = dfs(j, visited | (1 << j));
        if (ret < x) {
            ret = x;
            nxt = j;
        }
    }

    dp[i][visited][0] = ret + 1;
    dp[i][visited][1] = nxt;
    return dp[i][visited][0];
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    cout << dfs(0, 1) << endl;
    for (int i = 0, v = 1; i != -1;) {
        cout << i + 1 << ' ';
        i  = dp[i][v][1];
        v |= 1 << i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}