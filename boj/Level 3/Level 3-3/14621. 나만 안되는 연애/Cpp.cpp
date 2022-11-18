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
    vector<int> parents(n + 1);
    for (int i = 1; i <= n; i++)
        parents[i] = i;

    sort(
        edges.begin(), edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    int answer = 0;
    for (const auto& [v, u, w] : edges) {
        if (FindParent(parents, v) != FindParent(parents, u)) {
            UnionParent(parents, v, u);
            answer += w;
        }
    }

    int root = FindParent(parents, 1);
    for (int i = 2; i <= n; ++i) {
        if (FindParent(parents, i) != root) {
            return -1;
        }
    }

    return answer;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<char> info(N);
    for (char& x : info) {
        cin >> x;
    }

    vector<Node> edges;
    for (int i = 0; i < M; ++i) {
        int v, u, w;
        cin >> v >> u >> w;

        if (info[v - 1] == info[u - 1]) {
            continue;
        }

        edges.push_back({ v, u, w });
    }

    cout << Kruskal(N, edges);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
