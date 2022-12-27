#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
        if (i % 6 == 0) {
            cout << "Go! ";
        }
    }
    if (n % 6 != 0) {
        cout << "Go!\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
