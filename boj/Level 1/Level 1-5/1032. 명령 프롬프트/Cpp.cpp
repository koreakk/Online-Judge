#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string ret;
    cin >> ret;

    size_t length = ret.length();

    for (int i = 1; i < n; ++i) {
        string str;
        cin >> str;

        for (int j = 0; j < length; ++j) {
            if (ret[j] != str[j]) {
                ret[j] = '?';
            }
        }
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
