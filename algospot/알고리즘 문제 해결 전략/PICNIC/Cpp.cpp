#include <bits/stdc++.h>
using namespace std;

int N, M, A[10][10];

int dfs(int x, int visited) {
    if (visited == (1 << N) - 1) {
        return 1;
    }

    if (x > N) return 0;
    if (visited & (1 << x)) {
        return dfs(x + 1, visited);
    }

    visited |= 1 << x;
    int ret = 0;

    for (int i = 0; i < N; ++i) {
        if (visited & (1 << i) || !A[i][x]) {
            continue;
        }
        ret += dfs(x + 1, visited | (1 << i));
    }
    return ret;
}

void solve() {
    memset(A, 0, sizeof(A));

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        A[a][b] = A[b][a] = 1;
    }

    cout << dfs(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
