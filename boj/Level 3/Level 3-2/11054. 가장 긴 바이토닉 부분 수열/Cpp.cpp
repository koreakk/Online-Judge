#include <bits/stdc++.h>
using namespace std;

int N, A[1000], dp[1000][2];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            else if (A[i] < A[j]) {
                dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < N; ++i) {
        result = max(result, max(dp[i][0], dp[i][1]) + 1);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}