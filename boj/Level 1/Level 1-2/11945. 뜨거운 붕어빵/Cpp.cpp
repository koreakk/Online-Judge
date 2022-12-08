#include <bits/stdc++.h>
using namespace std;

int A[10][10];

void solve() {
    int N, M;
    cin >> N >> M;

    string buf;
    for (int i = 0; i < N; ++i) {
        cin >> buf;
        for (int j = 0; j < M; ++j) {
            A[i][j] = buf[j] - '0';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = M; --j >= 0;) {
            cout << A[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
