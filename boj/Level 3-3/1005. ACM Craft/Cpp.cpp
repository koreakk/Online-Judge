#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K, W, graph[1001][1001], dp[1001], info[1001], indegree[1000];

void TopologySort() {
    queue<int> q;
    
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (graph[v][i] == 0) {
                continue;
            }

            dp[i] = max(dp[i], info[i] + dp[v]);
            --indegree[i];
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }
}

void solve() {
    memset( graph,    0, sizeof(graph)    );
    memset( dp,       0, sizeof(dp)       );
    memset( info,     0, sizeof(info)     );
    memset( indegree, 0, sizeof(indegree) );

    cin >> N >> K;

    for (int i = 1; i <= N; ++i) {
        cin >> info[i];
        dp[i] = info[i];
    }

    for (int i = 0; i < K; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        ++indegree[v];
    }
    
    cin >> W;
    TopologySort();
    cout << dp[W] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}