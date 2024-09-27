#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll phi(ll n) {
    ll ret = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) {
        ret -= ret / n;
    }
    return ret;
}

int main() {
    ll p, q;
    cin >> p >> q;

    ll ret = 0;
    for (ll i = 1; i <= q/p; ++i) {
        ret += phi(i);
    }
    cout << ret + 1 << '\n';
    return 0;
}