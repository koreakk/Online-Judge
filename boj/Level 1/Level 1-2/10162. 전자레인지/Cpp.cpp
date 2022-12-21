#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n % 10 != 0) {
        cout << "-1\n";
        return;
    }

    cout << n / 300 << ' ';
    n %= 300;

    cout << n / 60 << ' ';
    n %= 60;

    cout << n / 10 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
