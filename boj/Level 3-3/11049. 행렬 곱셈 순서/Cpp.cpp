#include <bits/stdc++.h>
using namespace std;

int N, info[500][2], dp[500][500];

int f(int x, int y) {
    int val = info[y][0] * info[x][1];

    int res = INT_MAX;
    for (int i = y; i < x; ++i) {
        res = min(res, dp[i][y] + dp[x][i + 1] + val * info[i][1]);
    }

    return res;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> info[i][0] >> info[i][1];
    }

	for (int i = 1; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			dp[i][j] = f(i, j);
		}
	}

    cout << dp[N - 1][0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}