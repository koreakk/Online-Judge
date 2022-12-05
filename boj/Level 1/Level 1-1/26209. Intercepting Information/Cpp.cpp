#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t = 0;
    for (int i = 0; i < 8; ++i) {
        int x; cin >> x;
        if (x != 0 && x != 1) {
            t = 1;
        }
    }

    cout << (t ? 'F' : 'S');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}