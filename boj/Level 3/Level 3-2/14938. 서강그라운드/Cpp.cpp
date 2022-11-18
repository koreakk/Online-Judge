#include <iostream>
#include <algorithm>
#include <vector>   
using namespace std;

constexpr int INF = 100000000;
using GRAPH = vector<vector<int>>;  // adjacency matrix

GRAPH FloydWarshall(const GRAPH& graph) {
    int n = (int)graph.size();
    GRAPH dist = graph;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

void solve() {
    int N, M, R;
    cin >> N >> M >> R;

    vector<int> items(N);
    for (int& item : items) {
        cin >> item;
    }

    GRAPH graph(N, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < R; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        graph[v - 1][u - 1] = w;
        graph[u - 1][v - 1] = w;
    }

    GRAPH dist = FloydWarshall(graph);
    int result = 0;

    for (int i = 0; i < N; ++i) {
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] <= M) {
                count += items[j];
            }
        }
        result = max(result, count);
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
