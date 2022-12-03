#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> extended_gcd(ll a, ll b) {
    if (!a) { return { 0, 1 }; }
    auto [x, y] = extended_gcd(b % a, a);
    return { (y - (b / a) * x), x };
}

void solve() {
    auto next = [](ll& F1, ll& F2) {
        ll tmp = F2;
        F2 = F1 + F2;
        F1 = tmp;
    };

    ll N;
    cin >> N;

    ll A = (ll)1e9, B = (ll)1e9;
    for (ll F1 = 1, F2 = 1; F1 + F2 <= (ll)1e9; next(F1, F2)) {
        
        auto [x, y] = extended_gcd(F2, F1);
        x *= N, y *= N;

        ll k = min((ll)ceil((double)x / F1), (ll)ceil((double)-y / F2));

        x -= k * F1;
        y += k * F2;

        if (x < 0 || y < 0) {
            continue;
        }

        if (x + y < A + B) {
            A = y, B = x;
        }
    }

    if (A > B || A == 0) { next(A, B); }
    cout << A << ' ' << B << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}