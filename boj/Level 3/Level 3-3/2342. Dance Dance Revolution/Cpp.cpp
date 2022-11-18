#include <bits/stdc++.h>
using namespace std;

int info[5][5] = {
    {1, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};
int dp[100001][5][5];

void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    int i = 1;
    for (;; ++i) {
        int x; cin >> x;
        if (x == 0) break;

        for (int l = 0; l < 5; ++l) {
            for (int r = 0; r < 5; ++r) {
                if (dp[i - 1][l][r] == -1) continue;

                if (l != x && (dp[i][l][x] == -1 ||
                    dp[i - 1][l][r] + info[r][x] < dp[i][l][x])) 
                {
                    dp[i][l][x] = dp[i - 1][l][r] + info[r][x];
                }
                if (r != x && (dp[i][x][r] == -1 ||
                    dp[i - 1][l][r] + info[l][x] < dp[i][x][r])) 
                {
                    dp[i][x][r] = dp[i - 1][l][r] + info[l][x];
                }
            }
        }
    }

    int result = 10000000;
    for (int l = 0; l < 5; ++l) {
        for (int r = 0; r < 5; ++r) {
            if (dp[i - 1][l][r] != -1) {
                result = min(result, dp[i - 1][l][r]);
            }
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}