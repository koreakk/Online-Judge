#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int& x : A) {
        cin >> x;
    }

    int ret = 0;

    vector<int> L;
    L.reserve(A.size());

    for (int i = 0; i < N; ++i) {
        L.clear();
        L.push_back(A[i]);

        for (int j = i; j < N; ++j) {
            if (L.back() < A[j]) {
                L.push_back(A[j]);
            }
            else {
                *lower_bound(L.begin(), L.end(), A[j]) = A[j];
            }

            ret += (int)L.size();
        }
    }

    cout << ret << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}