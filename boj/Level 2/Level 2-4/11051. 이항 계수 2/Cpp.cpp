#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 10007;

int dp[1001][1001];

int f(int n, int k) {
    if (k == 1) { return n; }
    if (k == 0) { return 1; }
    if (n == k) { return 1; }

    if (!dp[n][k]) {
        dp[n][k] = f(n - 1, k - 1) + f(n - 1, k);
        dp[n][k] %= MOD;
    }

    return dp[n][k];
}

void solve() {
    int n, k;
    cin >> n >> k;

    cout << f(n, k) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}