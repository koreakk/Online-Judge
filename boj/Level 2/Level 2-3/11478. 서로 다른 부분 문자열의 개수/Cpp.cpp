#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;
    
    set<string> s;

    int len = (int)str.length();
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j <= len - i; ++j) {
            s.insert(str.substr(i, j));
        }
    }

    cout << s.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}