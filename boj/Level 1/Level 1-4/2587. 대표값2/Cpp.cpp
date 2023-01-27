#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A[5] = { 0 };
    for (int& a : A) { cin >> a; }

    sort(A, A + 5);

    int sum = 0;
    for (int a : A) { sum += a; }

    cout << sum / 5 << '\n';
    cout << A[2] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}