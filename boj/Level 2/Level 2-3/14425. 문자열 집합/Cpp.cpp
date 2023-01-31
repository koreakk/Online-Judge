#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    string str;
    set<string> S;

    for (int i = 0; i < N; ++i) {
        cin >> str;
        S.insert(str);
    }

    int ret = 0;
    for (int i = 0; i < M; ++i) {
        cin >> str;

        if (S.find(str) != S.end()) { ++ret; }
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}