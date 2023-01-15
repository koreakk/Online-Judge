#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    char ch;

    cin >> a >> ch >> b >> ch >> c;
    if (a + b == c) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
