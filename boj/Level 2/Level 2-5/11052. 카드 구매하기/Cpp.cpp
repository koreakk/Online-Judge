#include <bits/stdc++.h>
using namespace std;

int A[1000], N;
int dp[1000];

int dfs(int p) {
    if (!dp[p]) {
        int ret = A[p];
        for (int i=0; i<p; ++i) {
            ret = max(ret, dfs(i)+dfs(p-i-1));
        }
        dp[p] = ret;
    }
    return dp[p];
}

int main() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }

    cout << dfs(N-1) << '\n';
    return 0;
}
