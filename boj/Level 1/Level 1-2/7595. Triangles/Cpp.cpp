#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0) {
            return;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                cout << '*';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
