#include <bits/stdc++.h>
using namespace std;

int N, M, mInfo[100], cInfo[100], dp[101][10001];

void solve() {
    cin >> N >> M;
    int s = 0;
    for (int i = 0; i < N; ++i) cin >> mInfo[i];
    for (int i = 0; i < N; ++i) cin >> cInfo[i],
                                s += cInfo[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j <= s; ++j) {
            if (cInfo[i] <= j) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - cInfo[i]] + mInfo[i]);
            }
            else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    
    for (int i = 0; i <= s; ++i) {
        if (dp[N][i] >= M) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}