#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    int d = (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
    cout << ((d > 0) ? 1 : (d < 0) ? -1 : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
