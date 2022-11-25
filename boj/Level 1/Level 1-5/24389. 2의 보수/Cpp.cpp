#include <bits/stdc++.h>
using namespace std;

void solve() {
    unsigned int n;
    cin >> n;

    int ret = 0;
    for (n ^= ~n + 1; n; n &= n - 1) { ++ret; }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}