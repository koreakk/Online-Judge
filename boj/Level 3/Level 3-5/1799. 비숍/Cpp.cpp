#include <bits/stdc++.h>
using namespace std;

#define F1(y, x) ((y) + (x))
#define F2(y, x) ((y) - (x) + (N) + 1)

int N, A[10][10], V[2][20];

int dfs(int y, int x, int b) {
    int ret = 0;

    for (int i = y; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!A[i][j] || b != ((i + j + 1) & 1)) {
                continue;
            }

            if (V[0][F1(i, j)] || V[1][F2(i, j)]) {
                continue;
            }

            V[0][F1(i, j)] = 1;
            V[1][F2(i, j)] = 1;
            
            ret = max(ret, dfs(i, j, b) + 1);
            
            V[0][F1(i, j)] = 0;
            V[1][F2(i, j)] = 0;
        }
    }

    return ret;
}

void solve() {
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    cout << dfs(0, 0, 0) + dfs(0, 0, 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}