#include <bits/stdc++.h>
using namespace std;

int N, A[1000000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> res = { A[0] };
    for (int i = 1; i < N; ++i) {
        if (res.back() < A[i]) {
            res.push_back(A[i]);
        }
        else {
            *lower_bound(res.begin(), res.end(), A[i]) = A[i];
        }
    }

    cout << res.size() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}