#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> indegree(N);
    vector<vector<int>> graph(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;

        graph[A - 1].push_back(B - 1);
        ++indegree[B - 1];
    }

    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        if (indegree[i] == 0) {
            pq.push(-i);
        }
    }

    while (!pq.empty()) {
        int v = -pq.top();
        pq.pop();
        
        cout << v + 1 << ' ';

        for (int u : graph[v]) {
            if (--indegree[u] == 0) {
                pq.push(-u);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}