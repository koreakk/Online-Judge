#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x = 0, y = 0, r = -1;
    
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            int n; cin >> n;
            if (r < n) {
                r = n;
                y = i;
                x = j;
            }
        }
    }

    cout << r << '\n' << y << ' ' << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}