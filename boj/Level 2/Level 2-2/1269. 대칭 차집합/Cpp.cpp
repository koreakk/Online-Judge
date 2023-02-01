#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    set<int> A, B;

    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        A.insert(x);
    }

    for (int i = 0; i < M; ++i) {
        int x; cin >> x;
        B.insert(x);
    }

    int a = N;
    for (int x : A) {
        if (B.find(x) != B.end()) {
            --a;
        }
    }

    int b = M;
    for (int x : B) {
        if (A.find(x) != A.end()) {
            --b;
        }
    }

    cout << max(a, 0) + max(b, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}