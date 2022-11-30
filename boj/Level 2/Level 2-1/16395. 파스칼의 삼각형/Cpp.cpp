#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll BinomialCoefficient(ll n, ll r) {
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

    for (ll i = 0; i <= n; ++i) {
        dp[i][0] = 1;

        for (ll j = 1; j <= i; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][r];
}
void solve() {
    ll n, k;
    cin >> n >> k;

    cout << BinomialCoefficient(--n, --k) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}