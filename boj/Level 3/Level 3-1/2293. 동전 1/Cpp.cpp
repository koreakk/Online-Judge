#include <bits/stdc++.h>
using namespace std;

int dp[10001] = { 1 };
int N, K;

int main() {
    int c;

    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        cin >> c;

        for (int j=c; j<=K; ++j) {
            dp[j] += dp[j-c];
        }
    }

    cout << dp[K] << '\n';
    return 0;
}
