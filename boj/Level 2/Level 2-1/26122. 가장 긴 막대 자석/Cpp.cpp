#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k; cin >> k;

    int isN = -1, cnt = 0;
    vector<int> d;
    for (int i = 0; i < k; ++i) {
        char c; cin >> c;

        if (isN == -1) {
            if (c == 'N') isN = 1;
            else          isN = 0;
            ++cnt;
        }

        if (c == 'N') {
            if (isN == 1) {
                ++cnt;
                continue;
            }
            isN = 1;
            d.push_back(cnt);
            cnt = 1;
        }
        else {
            if (isN == 0) {
                ++cnt;
                continue;
            }
            isN = 0;
            d.push_back(cnt);
            cnt = 1;
        }
    }

    if (cnt != 0) {
        d.push_back(cnt);
    }

    int ret = 0;
    int N = (int)d.size();
    for (int i = 0; i < N - 1; ++i) {
        ret = max(ret, min(d[i], d[i + 1]) * 2);
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}