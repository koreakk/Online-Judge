#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(const vector<int>& A) {
    int N = (int)A.size();
    vector<int> dp(N, 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int i = 0;
    for (int j = 0; j < N; ++j) {
        if (i < dp[j]) {
            i = dp[j];
        }
    }

    vector<int> ret(i);

    for (int j = N - 1; j >= 0; --j) {
        if (dp[j] == i) {
            ret[--i] = A[j];
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

    vector<int> ret = LIS(A);

    cout << ret.size() << endl;
    for (int x : ret) {
        cout << x << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}