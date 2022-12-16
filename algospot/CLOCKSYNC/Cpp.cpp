#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 10000000;

const vector<int> SWITCHES[10] = {
    { 0, 1, 2         },
    { 3, 7, 9, 11     },
    { 4, 10, 14, 15   },
    { 0, 4, 5, 6, 7   },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15    },
    { 3, 14, 15       },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5   },
    { 3, 4, 5, 9, 13  }
};

int A[16];

int dfs(int x) {
    if (x >= 10) {
        for (int i = 0; i < 16; ++i) {
            if (A[i] != 12) {
                return INF;
            }
        }
        return 0;
    }

    int ret = INF;
    for (int i = 0; i < 4; ++i) {
        ret = min(ret, i + dfs(x + 1));

        for (int s : SWITCHES[x]) {
            A[s] = (A[s] == 12) ? 3 : A[s] + 3;
        }
    }

    return ret;
}

void solve() {
    for (int i = 0; i < 16; ++i) {
        cin >> A[i];
    }

    int ret = dfs(0);
    if (ret >= INF) { ret = -1; }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}