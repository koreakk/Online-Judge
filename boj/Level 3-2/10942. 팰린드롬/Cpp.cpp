#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int N, M, S, E, a[2001], dp[2001][2001];

void f(int l, int r) {
    while (l >= 0 && r < N) {
        if (a[l] != a[r])
            break;
        dp[l--][r++] = 1;
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    for (int i = 0; i < N; ++i) {
        f(i, i);
        f(i, i + 1);
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> S >> E;
        cout << dp[S - 1][E - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}