#include <bits/stdc++.h>
using namespace std;

constexpr double INF = 10000000.;

int N, A[16][2];
double W[16][16], dp[16][1 << 16];

double dfs(int i, int visited) {
    if (dp[i][visited]) {
        return dp[i][visited];
    }

    if (visited == (1 << N) - 1) {
        double ret = W[i][0];
        dp[i][visited] = ret ? ret : INF;
        return dp[i][visited];
    }

    double ret = INF;
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
        cin >> A[i][0] >> A[i][1];
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) { continue; }

            auto [x1, y1] = A[i];
            auto [x2, y2] = A[j];

            double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            W[i][j] = W[j][i] = d;
        }
    }

    cout << dfs(0, 1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(6);
    solve();
    return 0;
}