#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;

ll N, dp[8], tp[8];

void solve() {
    cin >> N;

    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        tp[0] = dp[1] + dp[2];
        tp[1] = dp[0] + dp[2] + dp[3];
        tp[2] = dp[0] + dp[1] + dp[3] + dp[4];
        tp[3] = dp[1] + dp[2] + dp[4] + dp[5];
        tp[4] = dp[2] + dp[3] + dp[5] + dp[6];
        tp[5] = dp[3] + dp[4] + dp[7];
        tp[6] = dp[4] + dp[7];
        tp[7] = dp[5] + dp[6];

        for (int j = 0; j < 8; ++j) {
            dp[j] = tp[j] % MOD;
        }
    }

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}