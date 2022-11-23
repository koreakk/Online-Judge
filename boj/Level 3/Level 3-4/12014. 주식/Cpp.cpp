#include <bits/stdc++.h>
using namespace std;

int LIS(const vector<int>& A) {
    vector<int> L = { A[0] };
    L.reserve(A.size());

    for (int x : A) {
        if (L.back() < x) {
            L.push_back(x);
        }
        else {
            *lower_bound(L.begin(), L.end(), x) = x;
        }
    }

    return static_cast<int>(L.size());
}

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int& x : A) {
        cin >> x;
    }

    cout << int(LIS(A) >= K) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << "\n";
        solve();
    }
    return 0;
}