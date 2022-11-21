#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<vector<int>> mInfo(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int w; cin >> w;
            mInfo[i][w - 1] = j;
        }
    }

    vector<queue<int>> wInfo(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int m; cin >> m;
            wInfo[i].push(m - 1);
        }
    }

    vector<int>  mPartner(n, -1);
    vector<bool> wFree(n, false);
    
    int freeCount = n;
    
    while (freeCount) {
        for (int w = 0; w < n; ++w) {
            if (wFree[w]) { continue; }

            int m = wInfo[w].front();
            wInfo[w].pop();

            if (mPartner[m] == -1) {
                mPartner[m] = w;
                wFree[w]    = true;
                --freeCount;
            }
            else if (mInfo[m][mPartner[m]] > mInfo[m][w]) {
                wFree[mPartner[m]] = false;
                mPartner[m] = w;
                wFree[w]    = true;
            }
        }
    }

    for (int w : mPartner) {
        cout << w + 1 << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}