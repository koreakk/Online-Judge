#include <bits/stdc++.h>
using namespace std;

int A[10001];

void solve() {
    int M, N;
    cin >> M >> N;

    A[1] = 1;
    for (int i = 2; i * i <= N; ++i) {
        if (A[i]) { continue; }

        for (int j = i * i; j <= N; j += i) {
            A[j] = 1;
        }
    }

    int sum      = 0;
    int minprime = 0;

    for (int i = N; i >= M; --i) {
        if (A[i] == 0) {
            sum      += i;
            minprime  = i;
        }
    }

    if (sum == 0) {
        cout << "-1\n";
        return;
    }

    cout << sum << '\n';
    cout << minprime << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}