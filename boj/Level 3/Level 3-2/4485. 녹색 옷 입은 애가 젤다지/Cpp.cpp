#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;

using node_type  = pair<int, pair<int, int>>;
using pq_type    = priority_queue<node_type, vector<node_type>, greater<node_type>>;

int graph[126][126], dist[126][126];

void Dijkstra(int n) {
    auto InRange = [&n](int x, int y) {
        return min(x, y) >= 0 && max(x, y) < n;
    };

    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    memset(dist, 0x70, sizeof(dist));
    pq_type pq;

    pq.emplace(graph[0][0], make_pair(0, 0));
    dist[0][0] = graph[0][0];

    while (!pq.empty()) {
        auto [weight, pos] = pq.top();
        auto [x, y]        = pos;
        pq.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (!InRange(nextX, nextY)) {
                continue;
            }

            int currDist = weight + graph[nextY][nextX];
            if (currDist < dist[nextY][nextX]) {
                dist[nextY][nextX] = currDist;
                pq.emplace(currDist, make_pair(nextX, nextY));
            }
        }
    }
}

int solve(int n) {
    memset(graph, 0x00, sizeof(graph));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    Dijkstra(n);
    return dist[n - 1][n - 1];
}

int main() {
    for (int i = 1;; ++i) {
        int N;
        cin >> N;
        if (N == 0) break;

        cout << "Problem " << i << ": " << solve(N) << endl;
    }

    return 0;
}