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
    int N; cin >> N;
    
    vector<int> A(N);
    for (int& x : A) {
        cin >> x;
    }

    cout << A.size() - LIS(A) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}