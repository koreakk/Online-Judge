#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

void solve() {
    map<string, string> dict;
    int n; cin >> n;
    string str;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> str; s = str;
        if (s.length() > 2)
            sort(s.begin() + 1, s.end() - 1);
        dict[s] = str;
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s.length() > 2)
            sort(s.begin() + 1, s.end() - 1);
        cout << dict[s] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}