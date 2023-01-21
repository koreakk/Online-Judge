#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long A, B, C;
    cin >> A >> B >> C;
    
    cout << A * max(B, C) / min(B, C) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}