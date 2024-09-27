#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<ll, 10001> phi_sum_table;

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

    for (int i = 1; i <= 10000; ++i) {
        phi_sum_table[i] = phi_sum_table[i-1] + phi(i);
    }

    ll t, n, i;
    cin >> t;
    while (t--) {
        cin >> i >> n;
        cout << i << ' ' << phi_sum_table[n] + 1 << '\n';
    }

    return 0;
}