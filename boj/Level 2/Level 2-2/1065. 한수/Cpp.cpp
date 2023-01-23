#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    if (x < 100) {
        return 1;
    }
    
    int d = x % 10;
    x /= 10;

    int diff = d - x % 10;

    while (x) {
        if (d - (x % 10) != diff) {
            return 0;
        }
        d = x % 10;
        x /= 10;
    }

    return 1;
}

void solve() {
    int N;
    cin >> N;

    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        ret += f(i);
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}