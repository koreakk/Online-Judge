#include <iostream>
using namespace std;

int X, dp[1000001], Prev[1000001];

void solve() {
    cin >> X;
    
    for (int i = 1; i < X; ++i) {
        for (int n : { i + 1, i * 2, i * 3 }) {
            if (n <= X && (!dp[n] || dp[n] > dp[i] + 1)) {
                dp[n]   = dp[i] + 1;
                Prev[n] = i;
            }
        }
    }

    cout << dp[X] << endl;
    for (int i = X; i != 0; i = Prev[i]) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
