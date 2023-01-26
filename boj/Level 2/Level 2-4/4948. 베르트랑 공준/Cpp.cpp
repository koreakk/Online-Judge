#include <bits/stdc++.h>
using namespace std;

constexpr int LEN = 246913;
int A[LEN];

void solve() {
    fill(A, A + LEN, 1);

    A[1] = 0;
    for (int i = 2; i * i < LEN; ++i) {
        for (int j = i * i; j < LEN; j += i) {
            A[j] = 0;
        }
    }

    for (int i = 1; i < LEN; ++i) {
        A[i] += A[i - 1];
    }

    int n;
    for(;;) {
        cin >> n;
        if (n == 0) { break; }

        cout << A[n * 2] - A[n] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}