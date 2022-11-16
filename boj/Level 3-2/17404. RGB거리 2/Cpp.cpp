#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

int INF = 1000000;
int N, a[1001][3], dp[1001][3];

int f(int x) {
    memcpy(dp, a, sizeof(dp));
    dp[1][0] += dp[0][x];
    dp[1][1] += dp[0][x];
    dp[1][2] += dp[0][x];
    dp[1][x] =  INF;

    for (int i = 2; i < N; ++i) {
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    int res = INF;
    for (int i = 0; i < 3; ++i) {
        if (i != x) {
            res = min(res, dp[N - 1][i]);
        }
    }
    return res;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i][0] >>
               a[i][1] >>
               a[i][2];
    }

    cout << min(f(0), min(f(1), f(2)));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}