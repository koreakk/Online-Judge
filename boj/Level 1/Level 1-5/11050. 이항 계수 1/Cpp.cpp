#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n <= 1) return 1;
    return n * f(n - 1);
}

void solve() {
    int n, k;
    cin >> n >> k;

    cout << f(n) / (f(k) * f(n - k)) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}