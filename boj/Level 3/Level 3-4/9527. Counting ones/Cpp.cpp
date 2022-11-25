#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll D[55];

ll f(ll x) {
    ll ret = x & 1;

    for (int i = 54; i >= 1; --i) {
        if (x & (1ll << i)) {
            x &= ~(1ll << i);
            ret += D[i - 1] + x + 1;
        }
    }
   
    return ret;
}

void solve() {
    D[0] = 1;
    for (int i = 1; i < 55; ++i) {
        D[i] = 2 * D[i - 1] + (1ll << i);
    }

    ll A, B;
    cin >> A >> B;
    
    cout << f(B) - f(A - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}