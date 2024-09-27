#include <iostream>

using namespace std;
using ll = long long;

ll phi(ll n) {
    ll ret = n;
    for (ll i = 2; i*i <= n; ++i) {
        if (n%i == 0) {
            ret -= ret / i;
            while (n%i == 0) {
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
    ll n;
    cin >> n;

    ll ret = -1;
    for (ll i = 1; i * i <= n; ++i) {
        if (n%i == 0) {
            if (i * phi(i) == n) {
                cout << i << '\n';
                return 0;
            }
            if ((n/i) * phi(n/i) == n) {
                ret = n/i;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}