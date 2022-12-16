#include <bits/stdc++.h>
using namespace std;

int N, L, A[1000];

void solve() {
    cin >> N >> L;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    double ret = 1000000.;
    for (int i = 0; i < N; ++i) {
        for (int j = i, s = 0; j < N; ++j) {
            s += A[j];
            if (j - i + 1 >= L) {
                ret = min(ret, (double)s / (j - i + 1));
            }
        }
    }

    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(8);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
