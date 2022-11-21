#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<char>   men(n), women(n);
    map<char, int> mTable, wTable;
    for (int i = 0; i < n; ++i) {
        char a; cin >> a;
        men[i]    = a;
        mTable[a] = i;
    }

    for (int i = 0; i < n; ++i) {
        char a; cin >> a;
        women[i]  = a;
        wTable[a] = i;
    }

    vector<queue<int>> mInfo(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 2; j < s.size(); ++j) {
            mInfo[mTable[s[0]]].push(wTable[s[j]]);
        }
    }

    vector<map<int, int>> wInfo(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 2; j < s.size(); ++j) {
            wInfo[wTable[s[0]]][mTable[s[j]]] = j - 2;
        }
    }

    vector<int>  wPartner(n, -1);
    vector<bool> mFree(n, false);
    
    int freeCount = n;
    
    while (freeCount) {
        for (int m = 0; m < n; ++m) {
            if (mFree[m]) { continue; }

            int w = mInfo[m].front();
            mInfo[m].pop();

            if (wPartner[w] == -1) {
                wPartner[w] = m;
                mFree[m]    = true;
                --freeCount;
            }
            else if (wInfo[w][wPartner[w]] > wInfo[w][m]) {
                mFree[wPartner[w]] = false;
                wPartner[w] = m;
                mFree[m]    = true;
            }
        }
    }

    vector<pair<char, char>> result(n);
    for (int i = 0; i < n; ++i) {
        char w = women[i];
        char m = men[wPartner[i]];

        result[i] = make_pair(m, w);
    }

    sort(result.begin(), result.end());
    for (auto [m, w] : result) {
        cout << m << ' ' << w << endl;
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