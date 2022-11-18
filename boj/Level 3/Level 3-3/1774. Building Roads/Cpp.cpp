#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    int v, u;
    double w;
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

void solve() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> posInfo(N);
    for (auto& pos : posInfo) {
        cin >> pos.first >> pos.second;
    }

    vector<Node> edges;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            const auto& [Ax, Ay] = posInfo[i];
            const auto& [Bx, By] = posInfo[j];

            double w = sqrt(pow(Ax - Bx, 2) + pow(Ay - By, 2));
            edges.push_back({ i, j, w });
        }
    }

    vector<int> parents(N);
    for (int i = 0; i < N; i++)
        parents[i] = i;

    for (int i = 0; i < M; ++i) {
        int v, u;
        cin >> v >> u;
        UnionParent(parents, v - 1, u - 1);
    }

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    double answer = 0;
    for (const auto& [v, u, w] : edges) {
        if (FindParent(parents, v) != FindParent(parents, u)) {
            UnionParent(parents, v, u);
            answer += w;
        }
    }

    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(2);

    solve();
    return 0;
}