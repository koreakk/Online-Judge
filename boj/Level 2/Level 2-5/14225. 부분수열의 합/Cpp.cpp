#include <bits/stdc++.h>
using namespace std;

bool S[2000001];
int N, A[20];

void dfs(int i, int t) {
    if (i < N) {
        S[A[i] + t] = true;
        dfs(i + 1, A[i] + t);
        dfs(i + 1, t);
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    dfs(0, 0);
    for (int i = 1;; ++i) {
        if (S[i] == false) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}