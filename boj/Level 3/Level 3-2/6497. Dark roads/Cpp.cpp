#include <iostream>
#include <algorithm>
#include <vector>   
using namespace std;

struct Node {
    int v, u, w;
};

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

int Kruskal(int n, vector<Node>& edges) {
    vector<int> parents(n);
    for (int i = 0; i < n; i++)
        parents[i] = i;

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    int answer = 0;
    for (const auto& [v, u, w] : edges) {
        if (FindParent(parents, v) != FindParent(parents, u)) {
            UnionParent(parents, v, u);
        }
        else {
            answer += w;
        }
    }

    return answer;
}

void solve() {
    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        vector<Node> edges(n);
        for (Node& edge : edges) {
            cin >> edge.v >>
                   edge.u >>
                   edge.w;
        }

        cout << Kruskal(m, edges) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
