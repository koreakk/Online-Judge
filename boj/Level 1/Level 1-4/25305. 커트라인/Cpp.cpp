#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int& x : A) { cin >> x; }

    sort(A.begin(), A.end(), greater{});

    cout << A[k - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}