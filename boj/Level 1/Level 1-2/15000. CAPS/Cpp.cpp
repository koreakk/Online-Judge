#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;

    for_each(str.begin(), str.end(), [](char& ch)
                                     {
                                        ch ^= 32;
                                     });
    cout << str << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
