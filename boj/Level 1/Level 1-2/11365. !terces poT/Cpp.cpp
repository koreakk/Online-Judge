#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;

    while (true) {
        getline(cin, s);
        if (s == "END") { break; }

        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
