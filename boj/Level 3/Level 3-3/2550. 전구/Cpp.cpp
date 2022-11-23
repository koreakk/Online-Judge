#include <bits/stdc++.h>
using namespace std;

int N, A[10000], B[10000], T[10001], dp[10000], before[10000];

void solve() {
    memset(before, -1, sizeof(before));

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        T[A[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        B[T[x]] = i;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (B[i] > B[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                before[i] = j;
            }
        }
    }

    int i = 0;
    for (int j = 0; j < N; ++j) {
        if (dp[i] < dp[j]) {
            i = j;
        }
    }

    vector<int> ret;
    for (; i != -1; i = before[i]) {
        ret.push_back(A[i]);
    }
    sort(ret.begin(), ret.end());

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