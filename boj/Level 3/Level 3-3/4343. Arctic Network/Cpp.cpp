#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>   
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
    int S, P;
    cin >> S >> P;

    vector<pair<int, int>> info(P);
    for (auto& pos : info) {
        cin >> pos.first >> pos.second;
    }

    vector<Node> edges;
    for (int i = 0; i < P - 1; ++i) {
        for (int j = i + 1; j < P; ++j) {
            auto [x1, y1] = info[i];
            auto [x2, y2] = info[j];

            double w = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            edges.push_back({ i, j, w });
        }
    }

    vector<int> parents(P);
    for (int i = 0; i < P; i++) {
        parents[i] = i;
    }

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    int    count  = 0;
    double answer = -1;
    for (const auto& [v, u, w] : edges) {
        if (count == P - S) break;

        if (FindParent(parents, v) != FindParent(parents, u)) {
            UnionParent(parents, v, u);
            answer = w;
            count += 1;
        }
    }

    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(2);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
