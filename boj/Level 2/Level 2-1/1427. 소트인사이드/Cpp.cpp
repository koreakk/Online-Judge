#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    sort(s.begin(), s.end(), greater{});
    
    for (char ch : s) { cout << ch; }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}