#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l = 0, r = 0;
    int u = 0, d = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c; cin >> c;
            if (c != 'G') {
                continue;
            }
            
            l = max(l, j), r = max(r, N - j - 1);
            u = max(u, i), d = max(d, N - i - 1);
        }
    }

    int r1 = N - l - 1 == r ? 0 : min(l, r);
    int r2 = N - u - 1 == d ? 0 : min(u, d);

    cout << r1 + r2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}