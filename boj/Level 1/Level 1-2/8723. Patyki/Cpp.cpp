#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A[3];
    cin >> A[0] >> A[1] >> A[2];

    if (A[0] == A[1] && A[0] == A[2] && A[1] == A[2]) {
        cout << "2\n";
        return;
    }

    sort(A, A + 3);

    int hypot = A[2];
    int n1 = A[0], n2 = A[1];

    if (n1 * n1 + n2 * n2 == hypot * hypot) {
        cout << "1\n";
        return;
    }

    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
