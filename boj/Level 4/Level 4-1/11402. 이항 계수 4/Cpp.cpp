#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[2001];

ll pow(ll base, ll exp, ll mod) {
    ll ret = 1;
    for (base %= mod; exp; exp >>= 1) {
        if (exp & 1) {
            ret *= base;
            ret %= mod;
        }
        base *= base;
        base %= mod;
    }
    return ret;
}

ll f(ll n, ll k, ll m) {
    if (n < k) return 0;
    return (dp[n] * pow(dp[k] * dp[n - k], m - 2ll, m)) % m;
}

void solve() {
    ll n, k, m;
    cin >> n >> k >> m;

    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
        dp[i] = (i * dp[i - 1]) % m;
    }

    ll ret = 1;
    for (; n && k; n /= m, k /= m) {
        ret *= f(n % m, k % m, m);
        ret %= m;
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}