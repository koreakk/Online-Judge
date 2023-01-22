#include <bits/stdc++.h>
using namespace std;

int A[10001];

int f(int x) {
    int nx = x;
        
    while (x) {
        nx += x % 10;
        x /= 10;
    }

    if (nx > 10000) return 0;
    return nx;
}

void solve() {
    for (int i = 1; i <= 10000; ++i) {
        A[f(i)] = 1;
    }

    for (int i = 1; i <= 10000; ++i) {
        if (A[i] == 0) { cout << i << ' '; }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}