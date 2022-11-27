#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, D;
    cin >> N >> D;

    int maxH = 0;
    vector<int> H(N);
    for (int& h : H) { 
        cin >> h;
        maxH = max(maxH, h);
    }

    ll l = max(maxH - D, 0);
    ll ret = 0;
    for (int h : H) {
        ret += max(0ll, h - l);
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}