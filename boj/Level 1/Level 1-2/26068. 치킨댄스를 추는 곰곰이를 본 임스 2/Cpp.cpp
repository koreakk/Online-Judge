#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        char x; int n;
        cin >> x >> x >> n;
        if (n <= 90) ++ret;
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}