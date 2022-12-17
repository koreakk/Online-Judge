#include <bits/stdc++.h>
using namespace std;

int N, K, A[150];

void solve() {
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0, j = 0; i < N; ++i, j = A[j]) {
        if (j == K) {
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}