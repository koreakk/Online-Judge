#include <bits/stdc++.h>
using namespace std;

int T[16], P[16], N;
int dp[16];

int main() {
    cin >> N;

    for (int i=0; i<N; ++i) {
        cin >> T[i] >> P[i];
        dp[i]=P[i];
    }

    for (int i=0; i<N; ++i) {
        for (int j=i+T[i]; j<N; ++j) {
            dp[j]=max(dp[j], dp[i]+P[j]);
        }
    }
    
    int ret=0;
    for (int i=0; i <= N; ++i) {
        if (i+T[i]<=N) {
            ret=max(ret, dp[i]);
        }
    }

    cout << ret << '\n';
    return 0;
}
