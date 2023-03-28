#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_prime(ll n) {
    if (n <= 1) { return false; }

    for (ll i = 2; i*i <= n; ++i) {
        if (n%i == 0) { return false; }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    for (;t--;) {
        ll n;
        cin >> n;

        for (;;++n) {
            if (!is_prime(n)) { continue; }
            cout << n << '\n';
            break;
        }
    }

    return 0;
}
