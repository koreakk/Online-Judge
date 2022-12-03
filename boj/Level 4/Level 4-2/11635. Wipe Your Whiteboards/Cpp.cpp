#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>
tuple<T, T, T> extended_gcd(T a, T b) {
    if (!a) {
        return { b, 0, 1 };
    }

    auto [g, x, y] = extended_gcd(b % a, a);
    return { g, (y - (b / a) * x), x };
}

void solve() {
    ll R, S, Q;
    cin >> R >> S >> Q;
    
    auto [g, x, y] = extended_gcd(R, -S);

    ll q = Q / g;
    ll r = llabs(S / g);
    ll s = llabs(R / g);

    ll A = x * q, B = -y * q;
    ll k = A <= 0 ? (-A) / r + 1 : -((A - 1) / r);

    A += k * r;
    B += k * s;
    if (B <= 0) {
        k = (-B) / s + 1;
        A += k * r;
        B += k * s;
    }
    
    cout << A << ' ' << B << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}