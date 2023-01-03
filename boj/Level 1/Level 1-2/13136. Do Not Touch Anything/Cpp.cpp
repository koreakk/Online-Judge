#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long r, c, n;
    cin >> r >> c >> n;

    cout << ((r+n-1) / n) * ((c+n-1) / n) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
