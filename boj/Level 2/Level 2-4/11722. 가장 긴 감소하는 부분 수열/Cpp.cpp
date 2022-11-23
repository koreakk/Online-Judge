#include <bits/stdc++.h>
using namespace std;

int LIS(const vector<int>& A) {
    int N = (int)A.size();
    vector<int> dp(A.size(), 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] < A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (ret < dp[i]) {
            ret = dp[i];
        }
    }

    return ret;
}

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int& x : A) {
        cin >> x;
    }

    cout << LIS(A) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}