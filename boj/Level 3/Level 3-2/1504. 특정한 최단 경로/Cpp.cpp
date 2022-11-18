#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

using node_type  = pair<int, int>;
using graph_type = vector<vector<node_type>>;
using pq_type    = priority_queue<node_type, vector<node_type>, greater<node_type>>;

vector<int> Dijkstra(const graph_type& graph, int src) {
    vector<int> distance(graph.size(), -1);
    distance[src] = 0;

    pq_type pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        for (auto [v, w] : graph[vertex]) {
            int currDist = w + weight;

            if (distance[v] == -1 || currDist < distance[v]) {
                distance[v] = currDist;
                pq.emplace(currDist, v);
            }
        }
    }

    return distance;
}

int solve(const graph_type& graph, int v1, int v2, int src, int dest) {
    auto d1 = Dijkstra(graph, v1);
    auto d2 = Dijkstra(graph, v2);

    if (d1[v2] == -1 || d1[src] == -1 || d1[dest] == -1) {
        return -1;
    }

    return min(d1[src] + d2[dest], d1[dest] + d2[src]) + d1[v2];
}

int main() {
    int N, E;
    cin >> N >> E;

    graph_type graph(N + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    int v1, v2;
    cin >> v1 >> v2;
    cout << solve(graph, v1, v2, 1, N) << endl;

    return 0;
}