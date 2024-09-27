#include <iostream>
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
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << phi(n+1) << '\n';
    }
    return 0;
}