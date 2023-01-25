#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    for (int i = 2; i * i <= N; ++i) {
        for (; N % i == 0; N /= i) {
            cout << i << '\n';
        }
    }

    if (N != 1) { cout << N << '\n'; }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}