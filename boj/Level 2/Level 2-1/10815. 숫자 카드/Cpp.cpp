#include <bits/stdc++.h>
using namespace std;

int A[500000];
int N, M;

void solve() {
    cin >> N ;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A + N);

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;

        cout << (int)binary_search(A, A + N, x) << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}