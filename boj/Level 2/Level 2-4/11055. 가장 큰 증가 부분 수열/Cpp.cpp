#include <bits/stdc++.h>
using namespace std;

int N, A[1000], dp[1000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += A[i];
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        result = max(result, dp[i]);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}