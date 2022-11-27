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
    int G, P;
    cin >> G >> P;

    vector<int> parents(G + 1);
    for (int i = 0; i <= G; ++i) {
        parents[i] = i;
    }

    int g, p, i = 0;
    for (; i < P; ++i) {
        cin >> g;
        p = Find(parents, g);

        if (p == 0) break;
        Union(parents, p, p - 1);
    }

    cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}