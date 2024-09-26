#include <bits/stdc++.h>
using ll = long long;

ll sol(ll n, ll mod) {
    // d'Ocagne's identity
    // F_n+m = (F_n-1 x F_n) + (F_m x F_n+1)
    std::pair<ll, ll> y(1, 0), x(1, 0);

    while (n) {
        if (n & 1) {
            y = std::make_pair(
                (y.first*(x.first + x.second) + y.second*x.first) % mod,
                (x.first*y.first + x.second*y.second) % mod
            );
        }
        x = std::make_pair(
            (x.first * (x.first + 2 * x.second)) % mod,
            (x.first * x.first + x.second * x.second) % mod
        );
        n >>= 1;
    }

    return (y.first * y.second) % mod;
}

int main(void) {
    ll n;
    std::cin >> n;
    std::cout << sol(n, 1000000007);
    return 0;
}