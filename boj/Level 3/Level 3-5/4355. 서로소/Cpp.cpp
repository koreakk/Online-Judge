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
    ll n;
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cout << ((n == 1) ? 0 : phi(n)) << '\n';
    }
    return 0;
}