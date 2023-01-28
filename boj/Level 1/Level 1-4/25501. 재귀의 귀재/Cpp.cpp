#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int count = 0;
    int ispalind = 1;
    int l = 0, r = s.length() - 1;

    while (1) {
        ++count;

        if (l >= r) { break; }

        if (s[l++] != s[r--]) {
            ispalind = 0;
            break;
        }
    }

    cout << ispalind << ' ';
    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}