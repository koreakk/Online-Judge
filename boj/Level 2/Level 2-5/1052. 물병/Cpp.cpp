#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> A;
    for (int i = 1; n; i += i, n >>= 1) {
        if (n & 1) {
            A.push_back(i);
        }
    }

    int l = A.size();
    if (l <= k) {
        cout << "0\n";
        return;
    }

    int ret = A[l - k];
    for (int i = l - k - 1; i >= 0; --i) {
        ret -= A[i];
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
