#include <bits/stdc++.h>
using namespace std;

int T[1500001], P[1500001], N;
int dp[1500001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i=0; i<N; ++i) {
        cin >> T[i] >> P[i];
    }

    for (int i=N-1; i>=0; --i) {
        if (i+T[i]<=N) {
            dp[i]=P[i]+dp[i+T[i]];
        }
        dp[i]=max(dp[i], dp[i+1]);
    }
    
    cout << dp[0] << '\n';
    return 0;
}
