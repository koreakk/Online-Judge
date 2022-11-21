#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<string> mName(n);
    map<string, int> mTable;
    for (int i = 0; i < n; ++i) {
        cin >> mName[i];
        mTable[mName[i]] = i;
    }

    vector<string> wName(n);
    map<string, int> wTable;
    for (int i = 0; i < n; ++i) {
        cin >> wName[i];
        wTable[wName[i]] = i;
    }

    vector<queue<int>> mInfo(n);
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        int    idx = mTable[name];

        for (int j = 0; j < n; ++j) {
            string wname; cin >> wname;
            mInfo[idx].push(wTable[wname]);
        }
    }

    vector<vector<int>> wInfo(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string name; cin >> name;
        int    idx = wTable[name];
        for (int j = 0; j < n; ++j) {
            string mname; cin >> mname;
            wInfo[idx][mTable[mname]] = j;
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

    for (int i = 0; i < n; ++i) {
        cout << mName[wPartner[i]] << ' '
             << wName[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}