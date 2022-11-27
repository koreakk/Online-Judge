#include <bits/stdc++.h>
using namespace std;

int Find(vector<int>& parents, int v) {
    if (parents[v] == v) return v;
    return parents[v] = Find(parents, parents[v]);
}

void Union(vector<int>& parents, int v, int u) {
    v = Find(parents, v);
    u = Find(parents, u);
    if (v < u) parents[u] = v;
    else parents[v] = u;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> parents(n + 1);
    for (int i = 0; i <= n; ++i) {
        parents[i] = i;
    }

    int o, a, b;
    for (int i = 0; i < m; ++i) {
        cin >> o >> a >> b;

        if (o) {
            cout << (Find(parents, a) == Find(parents, b) ?
                     "YES\n" : "NO\n");
        }
        else {
            Union(parents, a, b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}