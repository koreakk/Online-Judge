#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int x, cnt = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        if (x == n) { ++cnt; }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
