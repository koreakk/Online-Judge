#include <bits/stdc++.h>
using namespace std;
#define W(x, y) (int(pow((x) - (y), 2)))

int N, X[2000], Y[2000], dp[2000][2000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) { cin >> X[i]; }
    for (int i = 0; i < N; ++i) { cin >> Y[i]; }

    dp[0][0] = W(X[0], Y[0]);
    for (int j = 1; j < N; ++j) {
        dp[0][j] = dp[0][j - 1] + W(X[0], Y[j]);
    }

    for (int i = 1; i < N; ++i) {
        dp[i][0] = dp[i - 1][0] + W(X[i], Y[0]);
        for (int j = 1; j < N; ++j) {
            dp[i][j] = min(
                dp[i - 1][j - 1],
                min(dp[i][j - 1], dp[i - 1][j])
             ) + W(X[i], Y[j]);
        }
    }

    cout << dp[N - 1][N - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
