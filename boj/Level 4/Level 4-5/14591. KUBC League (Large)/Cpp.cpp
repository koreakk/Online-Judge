#include <bits/stdc++.h>
using namespace std;

int N, W[2000][2000], visited[2000];

void dfs(vector<int>& in, int i) {
    visited[i] = 1;
    for (int j = 0; j < N; ++j) {
        if (visited[j] || !W[i][j]) { continue; }
        dfs(in, j);
    }
    in.push_back(i + 1);
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    vector<int> ret; dfs(ret, 0);

    int len = (int)ret.size();
    cout << len << endl;
    for (int i = len - 1; i >= 0; --i) {
        cout << ret[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}