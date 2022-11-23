#include <bits/stdc++.h>
using namespace std;

int N, A[2000], dp[2000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] < A[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        if (ret < dp[i] + 1) {
            ret = dp[i] + 1;
        }
    }

    cout << N - ret << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}