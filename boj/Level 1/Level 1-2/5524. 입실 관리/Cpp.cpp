#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for_each(s.begin(), s.end(), [&](char& ch)
                                     {
                                         ch |= 32; 
                                     });
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
