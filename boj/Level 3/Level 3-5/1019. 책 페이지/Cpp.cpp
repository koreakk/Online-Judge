#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll ret[10] = { 0 };

    ll lo = 1, hi, di = 1;
    cin >> hi;

    while (lo <= hi) {
        while (lo % 10 != 0 && lo <= hi) {
            for (ll n = lo++; n > 0; n /= 10) {
                ret[n % 10] += di;
            }
        }

        while (hi % 10 != 9 && lo <= hi) {
            for (ll n = hi--; n > 0; n /= 10) {
                ret[n % 10] += di;
            }
        }

        if (lo <= hi) {
            ll val = (hi / 10 - lo / 10 + 1) * di;
            for (int i = 0; i < 10; ++i) {
                ret[i] += val;
            }

            lo /= 10, hi /= 10;
            di *= 10;
        }
    }

    for (int i = 0; i < 10; ++i) {
        cout << ret[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}