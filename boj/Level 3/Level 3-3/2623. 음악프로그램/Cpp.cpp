#include <bits/stdc++.h>
using namespace std;

vector<int> TopologySort(int N, const vector<pair<int, int>>& edges) {
    vector<int>         indegree(N + 1);
    vector<vector<int>> graph(N + 1);

    for (const auto& [v, u] : edges) {
        graph[v].push_back(u);
        ++indegree[u];
    }

    vector<int> result;
    result.reserve(N);

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        result.push_back(v);
        q.pop();

        for (int i : graph[v]) {
            if (--indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    return result;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int count; cin >> count;
        int v = -1, u = -1;
        for (int j = 0; j < count; ++j, u = v) {
            cin >> v;
            if (u != -1) {
                edges.emplace_back(u, v);
            }
        }
    }

    auto result = TopologySort(N, edges);
    if ((int)result.size() < N) cout << "0\n";
    else {
        for (int x : result) {
            cout << x << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}