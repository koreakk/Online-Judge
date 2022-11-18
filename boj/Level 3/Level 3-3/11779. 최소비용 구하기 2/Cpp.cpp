#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using node_type  = pair<int, int>;  // weight, vertex
using graph_type = vector<vector<node_type>>;
using pq_type    = priority_queue<node_type, vector<node_type>, greater<node_type>>;

pair<vector<int>, vector<int>>
Dijkstra(const graph_type& graph, int source) {
    vector<int> distance(graph.size(), -1);
    vector<int> previous(graph.size(),  0);
    distance[source] = 0;

    pq_type pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if (distance[vertex] == -1 || weight <= distance[vertex]) {
            for (auto [w, v] : graph[vertex]) {
                int currDist = w + weight;

                if (distance[v] == -1 || currDist < distance[v]) {
                    distance[v] = currDist;
                    previous[v] = vertex;
                    pq.emplace(currDist, v);
                }
            }
        }

    }

    return { distance, previous };
}

int main() {
    int N, M;
    cin >> N >> M;

    graph_type graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph[src].emplace_back(weight, dest);
    }

    int src, dest;
    cin >> src >> dest;
    
    auto [dist, prev] = Dijkstra(graph, src);
    vector<int> res;
    for (int vertex = dest; vertex != prev[src]; vertex = prev[vertex]) {
        res.push_back(vertex);
    }

    cout << dist[dest] << endl;
    cout << res.size() << endl;
    for (auto riter = res.rbegin(); riter != res.rend(); ++riter) {
        cout << *riter << ' ';
    }
    cout << endl;

    return 0;
}