#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using node_type = pair<int, int>;  // weight, vertex
using graph_type = vector<vector<node_type>>;
using pq_type = priority_queue<node_type, vector<node_type>, greater<node_type>>;
using distance_type = vector<priority_queue<int>>;

vector<int> Dijkstra(const graph_type& graph, int source, int k) {
    distance_type distance(graph.size());
    distance[source].emplace(0);

    pq_type pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        for (auto [w, v] : graph[vertex]) {
            int currDist = w + weight;

            if (distance[v].size() < k) {
                distance[v].emplace(currDist);
                pq.emplace(currDist, v);
            }
            else if (distance[v].top() > currDist) {
                distance[v].pop();
                distance[v].emplace(currDist);
                pq.emplace(currDist, v);
            }
        }
    }

    vector<int> result(graph.size() - 1);
    for (int i = 1; i < graph.size(); ++i) {
        result[i - 1] = distance[i].size() != k ?
                        -1:
                        distance[i].top();
    }

    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    graph_type graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;

        graph[src].emplace_back(weight, dest);
    }

    for (int dist : Dijkstra(graph, 1, k)) {
        cout << dist << endl;
    }

    return 0;
}