#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int src, dest, weight;
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

int Kruskal(int n, vector<Node>& edges) {
    vector<int> parents(n + 1);
    for (int i = 0; i <= n; i++)
        parents[i] = i;

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.weight < r.weight;
        }
    );

    int answer = 0;
    for (const auto& [x, y, weight] : edges) {
        if (FindParent(parents, x) != FindParent(parents, y)) {
            UnionParent(parents, x, y);
            answer += weight;
        }
    }

    return answer;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Node> edges(E);
    for (Node& edge : edges) {
        cin >> edge.src   >>
               edge.dest  >>
               edge.weight;
    }

    cout << Kruskal(V, edges) << endl;
}