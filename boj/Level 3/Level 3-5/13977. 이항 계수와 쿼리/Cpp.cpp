#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

pair<vector<ll>, vector<ll>> binomialCompute(ll n, ll mod) {
    vector<ll> fac(n + 1ll), inv(n + 1ll);

    fac[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        fac[i] = i * fac[i - 1];
        fac[i] %= mod;
    }

    inv[n] = pow(fac[n], mod - 2ll, mod);
    for (ll i = n - 1; i >= 0; --i) {
        inv[i] = (i + 1) * inv[i + 1];
        inv[i] %= mod;
    }

    return { fac, inv };
}

void solve() {
    const ll MAX_N = 4000000, MOD = 1000000007;
    const auto [fac, inv] = binomialCompute(MAX_N, MOD);

    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        ll n, k;
        cin >> n >> k;

        cout << ((fac[n] * inv[k]) % MOD) * inv[n - k] % MOD << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}