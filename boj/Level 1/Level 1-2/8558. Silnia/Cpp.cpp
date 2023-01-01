#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int info[] = { 1, 1, 2, 6, 4, 0 };

    if (n > 5) { n = 5; }
    
    cout << info[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
