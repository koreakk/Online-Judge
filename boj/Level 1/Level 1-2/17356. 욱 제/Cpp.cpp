#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B;
    cin >> A >> B;

    double M = (double)(B - A) / 400.;
    cout << 1. / (1. + pow(10, M)) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
