#include <bits/stdc++.h>
using namespace std;

void solve() {
    int R, C;
    cin >> R >> C;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << '*';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}