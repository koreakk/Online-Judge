#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#pragma warning(disable : 4996)

using position_type = pair<int, int>;
using node_type = pair<int, position_type>;
using graph_type = vector<vector<int>>;
using pq_type = priority_queue<node_type, vector<node_type>, greater<node_type>>;
using distance_type = vector<vector<int>>;

distance_type Dijkstra(graph_type graph, int size, int x, int y) {
    auto InRange = [&](int x, int y) {
        return x >= 0 && x < size && y >= 0 && y < size;
    };

    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    distance_type distance(size + 1);
    for (int i = 0; i < size; ++i) {
        distance[i].resize(size + 1, -1);
    }
    distance[y][x] = 0;

    pq_type pq;
    pq.emplace(0, make_pair(x, y));

    while (!pq.empty()) {
        auto [weight, position] = pq.top();
        auto [x, y] = position;
        pq.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (!InRange(nextX, nextY)) {
                continue;
            }

            int currDist = weight + static_cast<int>(graph[nextY][nextX] == 0);
            if (distance[nextY][nextX] == -1 || currDist < distance[nextY][nextX]) {
                distance[nextY][nextX] = currDist;
                pq.emplace(currDist, make_pair(nextX, nextY));
            }
        }
    }

    return distance;
}

int main() {
    int N;
    scanf("%d", &N);

    graph_type graph(N);
    for (int i = 0; i < N; ++i) {
        graph[i].resize(N);
        for (int j = 0; j < N; ++j) {
            scanf("%1d", &graph[i][j]);
        }
    }

    printf("%d\n", Dijkstra(graph, N, 0, 0)[N - 1][N - 1]);
    return 0;
}
