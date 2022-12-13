#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000000;

int dp[100][10][1 << 10], N;

void solve() {
    cin >> N;

    for (int i = 1; i < 10; ++i) {
        dp[0][i][1 << i] = 1;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 10; ++j) {
            int m = 1 << j;

            for (int k = 0; k < (1 << 10); ++k) {
                for (int d : {j - 1, j + 1}) {
                    if (d < 0 || d > 9) {
                        continue;
                    }

                    dp[i][j][k | m] += dp[i - 1][d][k];
                    dp[i][j][k | m] %= MOD;
                }
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < 10; ++i) {
        ret += dp[N - 1][i][(1 << 10) - 1];
        ret %= MOD;
    }

    cout << ret << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
