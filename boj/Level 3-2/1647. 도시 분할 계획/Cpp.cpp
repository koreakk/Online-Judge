#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int x, y, w;
};

int FindParent(vector<int>& parents, int x) {
    if (parents[x] == x) return x;
    return parents[x] = FindParent(parents, parents[x]);
}

void UnionParent(vector<int>& parents, int x, int y) {
    x = FindParent(parents, x);
    y = FindParent(parents, y);
    if (x < y) parents[y] = x;
    else parents[x] = y;
}

long long Kruskal(int n, vector<Node>& edges) {
    vector<int> parents(n + 1);
    for (int i = 1; i <= n; i++)
        parents[i] = i;

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.w < r.w;
        }
    );

    int maxWeight    = 0;
    long long answer = 0;
    for (const auto& [x, y, w] : edges) {
        if (FindParent(parents, x) != FindParent(parents, y)) {
            UnionParent(parents, x, y);
            answer += w;
            maxWeight = max(maxWeight, w);
        }
    }

    return answer - maxWeight;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<Node> edges(M);
    for (auto& [x, y, w] : edges) {
        cin >> x >> y >> w;
    }

    cout << Kruskal(N, edges) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}