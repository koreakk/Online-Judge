#include <iostream>
#include <cmath>
using namespace std;

int m, k, dp[900][5001], info[900];

bool f(int n) {
    int x = 0;
    for (int i = n; i; i /= 10) {
        x += i % 10;
    }
    return n % x == 0;
}

void solve() {
    cin >> m >> k;

    int idx = 0;
    for (int i = 1; i <= m; ++i) {
        if (f(i)) {
            info[++idx] = i;
        }
    }
    for (int i = 1; i <= idx; ++i) {
        dp[i][0] = 1;
        int x    = info[i];

        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j] % k;
            if (j >= x)
                dp[i][j] += dp[i][j - x] % k;
            dp[i][j] %= k;
        }
    }

    cout << dp[idx][m] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}