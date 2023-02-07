#include <bits/stdc++.h>
using namespace std;

int A[10001], dp[10001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    dp[1] = A[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(A[i-1] + A[i] + dp[i-3],
                    max(dp[i-1], A[i] + dp[i-2]));
    }

    cout << dp[n] << '\n';
    return 0;
}
