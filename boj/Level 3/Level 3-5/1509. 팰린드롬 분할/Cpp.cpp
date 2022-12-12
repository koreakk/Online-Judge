#include <bits/stdc++.h>
using namespace std;

int dp[2500], N;
string A;

void f(int lo, int hi) {
    for (; lo >= 0 && hi < N &&
           A[lo] == A[hi]; --lo, ++hi)
    {
        int val = (lo ? dp[lo - 1] : 0) + 1;
        if (dp[hi] == 0 || dp[hi] > val) {
            dp[hi] = val;
        }
    }
}

void solve() {
    cin >> A;

    N = int(A.size());

    for (int i = 0; i < N; ++i) {
        f(i, i);
        f(i, i + 1);
    }
    
    cout << dp[N - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
