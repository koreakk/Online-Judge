#include <bits/stdc++.h>
using namespace std;

void solve() {
    string A, B;
    cin >> A >> B;

    string l = A, r = B;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    if (l != r) {
        cout << "-1\n";
        return;
    }

    int N = int(A.size());

    int k = N;
    int i = N - 1, j = 0;
    while (i >= j) {
        if (A[--k] != B[i]) { ++j; }
        else                { --i; }
    }

    cout << j << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}