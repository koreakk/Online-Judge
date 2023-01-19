#include <bits/stdc++.h>
using namespace std;

#define pi (3.141592)

void solve() {
    int d1, d2;
    cin >> d1 >> d2;

    cout << 2 * (d2 * pi + d1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(7);
    solve();
    return 0;
}