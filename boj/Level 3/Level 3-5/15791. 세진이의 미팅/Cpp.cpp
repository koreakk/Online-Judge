#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 1000000007;

ll pow(ll base, ll exp) {
    ll ret = 1;
    for (base %= MOD; exp; exp >>= 1) {
        if (exp & 1) {
            ret *= base;
            ret %= MOD;
        }
        base *= base;
        base %= MOD;
    }
    return ret;
}

ll fac(ll base) {
    ll ret = 1;
    for (int i = 1; i <= base; ++i) {
        ret *= i % MOD;
        ret %= MOD;
    }
    return ret;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ret = fac(n) * pow(fac(k) * fac(n - k), MOD - 2ll);
    ret %= MOD;

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}