#include <bits/stdc++.h>
using namespace std;

int N, A[20];

int dfs(int i, int t) {
    if (i >= N) { return 0; }

    return dfs(i + 1, t - A[i]) +
        dfs(i + 1, t) + (int)(A[i] == t);
}

void solve() {
    int t;
    cin >> N >> t;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << dfs(0, t) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(16);
    solve();
    return 0;
}