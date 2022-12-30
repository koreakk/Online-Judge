#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;

        cout << string(str.begin(), unique(str.begin(), str.end())) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
