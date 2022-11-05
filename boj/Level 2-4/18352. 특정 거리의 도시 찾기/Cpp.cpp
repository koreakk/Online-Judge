#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int src, dest;
        cin >> src >> dest;

        graph[src].push_back(dest);
    }
 
    vector<int> dist(N + 1, -1);
    dist[X] = 0;

    queue<int>  q;
    q.push(X);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int v : graph[vertex]) {
            if (dist[v] == -1) {
                dist[v] = dist[vertex] + 1;
                q.push(v);
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == K) {
            res.push_back(i);
        }
    }

    if (res.empty()) {
        cout << -1 << endl;
    }
    else {
        for (int x : res) {
            cout << x << endl;
        }
    }
    
    return 0;
}