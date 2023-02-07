#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll md = 1000000000;
ll dp[101][10];

int main() {
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1ll;
    }

    for (int i = 2; i <= 100; ++i) {
        dp[i][0] = (dp[i][0] + dp[i-1][1]) % md;
        dp[i][9] = (dp[i][9] + dp[i-1][8]) % md;

        for (int j = 1; j <= 8; ++j) {
            dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % md;
            dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % md;
        }
    }

    int n;
    cin >> n;

    int ret = 0;
    for (int i = 0; i <= 9; ++i) {
        ret = (ret + dp[n][i]) % md;
    }

    cout << ret << '\n';
    return 0;
}
