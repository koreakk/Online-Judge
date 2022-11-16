#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int>         indegree(N + 1);
    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int v, u;
        cin >> v >> u;

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

    for (int x : result) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}