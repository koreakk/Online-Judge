#include <bits/stdc++.h>
using ll = long long;

ll fib(ll n, ll mod) {
    // d'Ocagne's identity
    // F_n+m = (F_n-1 x F_n) + (F_m x F_n+1)
    std::pair<ll, ll> y(0, 1), x(1, 0);

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

    return y.first;
}

int main(void) {
    ll n, m;
    std::cin >> n >> m;
    std::cout << fib(std::gcd(n, m), 1000000007);
    return 0;
}