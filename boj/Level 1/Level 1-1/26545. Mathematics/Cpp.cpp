#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        ret += x;
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
