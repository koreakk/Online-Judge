#include <bits/stdc++.h>
using ll = long long;

ll pow(ll n, ll r, ll mod) {
    ll ret = 1;
    while (r) {
        if (r&1) {
            ret = (ret * n) % mod;
        }
        n = (n * n) % mod;
        r >>= 1;
    }
    return ret;
}

ll per(ll n, ll r, ll mod) {
    ll ret = 1;
    for (ll i = r + 1; i <= n; ++i) {
        ret = (ret * i) % mod;
    }
    return ret;
}

ll comb(ll n, ll r, ll p) { // p is prime
    return (per(n, n-r, p) * pow(per(r, 1, p), p-2, p)) % p;
}

int main() {
    ll k, n;
    std::cin >> k >> n;
    std::cout << comb(n+k, k+1, 1e9+7) << '\n';
    return 0;
}
