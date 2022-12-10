#include <bits/stdc++.h>
using namespace std;

void solve() {
    double X(0), Y(0);

    while (true) {
        cin >> X;
        if (X < 0) { break; }

        Y = X * 0.167;
        cout << "Objects weighing "
             << X
             << " on Earth will weigh "
             << Y
             << " on the moon.\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(2);
    solve();
    return 0;
}
