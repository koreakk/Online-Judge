#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;
long long Prim(int n, const vector<vector<int>>& graph) {
    vector<bool> visited(n);

    PQ pq;
    pq.emplace(0, 0);

    long long answer = 0;
    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = true;
        answer += weight;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                pq.emplace(graph[vertex][i], i);
            }
        }
    }

    return answer;
}

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> graph(N);
    for (vector<int>& edges : graph) {
        edges.resize(N);

        for (int& edge : edges) {
            cin >> edge;
        }
    }

    cout << Prim(N, graph) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}