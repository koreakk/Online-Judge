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

long long solve(int n, vector<Node>& edges) {
    vector<int> parents(n + 1);
    for (int i = 1; i <= n; ++i)
        parents[i] = i;

    sort(
        edges.begin(),
        edges.end(),
        [](const Node& l, const Node& r) {
            return l.weight < r.weight;
        }
    );

    long long answer = 0;
    for (const auto& [x, y, weight] : edges) {
        if (FindParent(parents, x) != FindParent(parents, y)) {
            UnionParent(parents, x, y);
        } 
        else {
            answer += weight;
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

int main() {
    int N, M;
    cin >> N >> M;

    vector<Node> edges(M);
    for (Node& edge : edges) {
        cin >> edge.src   >>
               edge.dest  >>
               edge.weight;
    }

    cout << solve(N, edges) << endl;
}