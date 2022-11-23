#include <bits/stdc++.h>
using namespace std;

int N, A[500], dp[500];

void solve() {
    cin >> N;

    int len = 0;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;

        len = max(len, a);
        A[a - 1] = b;
    }

    for (int i = 0; i < len; ++i) {
        if (A[i] == 0) { continue; }

        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j] && A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ret = 0, cnt_0 = 0;
    for (int i = 0; i < len; ++i) {
        ret = max(ret, dp[i] + 1);
        cnt_0 += A[i] ? 0 : 1;
    }

    cout << len - ret - cnt_0 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}