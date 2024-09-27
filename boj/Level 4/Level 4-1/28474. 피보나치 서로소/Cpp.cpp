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
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 2) {
            cout << n - 1 << '\n';
        }
        else if (n & 1) {
            cout << phi(n) << '\n';
        }
        else {
            cout << phi(n) + phi(n / 2) << '\n';
        }
    }

    return 0;
}