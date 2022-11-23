#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> A(N);
    for (auto& x : A) {
        cin >> x.first >> x.second;
    }

    sort(A.begin(), A.end());

    vector<int> info(N);

    vector<int> L = { A[0].second };
    L.reserve(A.size());

    for (int i = 0; i < N; ++i) {
        if (L.back() < A[i].second) {
            L.push_back(A[i].second);
            info[i] = (int)L.size();
        }
        else {
            auto it = lower_bound(L.begin(), L.end(), A[i].second);
            *it     = A[i].second;
            info[i] = (int)(it - L.begin() + 1);
        }
    }

    vector<int> ret;

    int i = (int)L.size(), j = N - 1;
    for (; j >= 0; --j) {
        if (info[j] == i) {
            --i; continue;
        }

        ret.push_back(A[j].first);
    }

    cout << ret.size() << '\n';

    sort(ret.begin(), ret.end());
    for (int x : ret) {
        cout << x << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}