#include <iostream>
#include <vector>
using namespace std;

int FindParent(vector<int>& parents, int v) {
    if (parents[v] == v) return v;
    return parents[v] = FindParent(parents, parents[v]);
}

void UnionParent(vector<int>& parents, int v, int u) {
    v = FindParent(parents, v);
    u = FindParent(parents, u);
    if (v < u) parents[u] = v;
    else parents[v] = u;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> parents(N);
    for (int i = 0; i < N; ++i)
        parents[i] = i;

    for (int i = 1; i <= M; ++i) {
        int v, u;
        cin >> v >> u;

        if (FindParent(parents, v) == FindParent(parents, u)) {
            cout << i << endl;
            return;
        }
        UnionParent(parents, v, u);
    }
    cout << "0\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}