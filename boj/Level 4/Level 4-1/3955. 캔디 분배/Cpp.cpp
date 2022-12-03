#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> extended_gcd(int a, int b) {
    auto swap = [](int& a, int& b, int c, int d) {
        a = c, b = d;
    };

    int s = 0, old_s = 1;
    int t = 1, old_t = 0;
    int r = b, old_r = a;

    while (r) {
        int quotient = old_r / r;
        swap(old_r, r, r, old_r - quotient * r);
        swap(old_s, s, s, old_s - quotient * s);
        swap(old_t, t, t, old_t - quotient * t);
    }
    
    return { old_r, old_s, old_t };
}

void solve() {
    int K, C;
    cin >> K >> C;

    auto [g, x, y] = extended_gcd(K, C);
   
    if (g == 1) {
        int nx = -1, ny = -1;
        for (int n = 0;; ++n) {
            nx = -x + n * C;
            ny =  y + n * K;

            if (ny > int(1e9)) { break; }

            if (nx > 0 && ny >= 0) {
                cout << ny << '\n';
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}