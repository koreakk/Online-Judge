#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using node_type = pair<int, int>;  // weight, vertex
using graph_type = vector<vector<node_type>>;
using pq_type = priority_queue<node_type, vector<node_type>, greater<node_type>>;
using distance_type = vector<int>;
using previous_type = vector<vector<int>>;

pair<distance_type, previous_type> Dijkstra(const graph_type& graph, int source) {
    distance_type distance(graph.size(), -1);
    previous_type previous(graph.size());
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
                    previous[v].clear();
                    previous[v].emplace_back(vertex);
                    pq.emplace(currDist, v);
                }
                else if (currDist == distance[v]) {
                    previous[v].emplace_back(vertex);
                }
            }
        }
    }

    return { distance, previous };
}

void DeleteEdge(graph_type& graph, const previous_type& prev, int dest) {
    auto Delete = [&](int src, int dest) {
        auto& v = graph[src];
        v.erase(
            remove_if(
                v.begin(),
                v.end(),
                [&](node_type x) { return x.second == dest; }
            ),
            v.end()
        );
    };

    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.emplace(dest);

    while (!q.empty()) {
        int dest = q.front();
        q.pop();

        if (!visited[dest]) {
            for (int src : prev[dest]) {
                Delete(src, dest);
                q.emplace(src);
            }
            visited[dest] = true;
        }
    }
}

int solve(graph_type& graph, int src, int dest) {
    DeleteEdge(graph, Dijkstra(graph, src).second, dest);
    return Dijkstra(graph, src).first[dest];
}

int main() {
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }

        int S, D;
        cin >> S >> D;

        graph_type graph(N);
        for (int i = 0; i < M; ++i) {
            int src, dest, weight;
            cin >> src >> dest >> weight;
            graph[src].emplace_back(weight, dest);
        }

        cout << solve(graph, S, D) << endl;
    }

    return 0;
}