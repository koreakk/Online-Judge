#include <iostream>
#include <vector>
#include <queue>
#define INF (100000000)
using namespace std;

using position_type = pair<int, int>;   // x, y
using node_type     = pair<int, position_type>; // weight, [x, y]
using pq_type       = priority_queue<node_type, vector<node_type>, greater<node_type>>;

int solve(const vector<vector<int>>& maze) {
    auto InRange = [&](int x, int y) {
        return y >= 0 && y < maze.size() &&
               x >= 0 && x < maze[0].size();
    };

    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    vector<vector<int>> dist(maze.size());
    for (int i = 0; i < dist.size(); ++i) {
        dist[i].resize(maze[0].size(), INF);
    }
    dist[0][0] = 0;

    pq_type pq;
    pq.emplace(0, make_pair(0, 0));

    while (!pq.empty()) {
        auto [weight, pos] = pq.top();
        auto [x, y] = pos;
        pq.pop();

        if (weight <= dist[y][x]) {
            for (int i = 0; i < 4; ++i) {
                int nextX = dx[i] + x;
                int nextY = dy[i] + y;

                if (InRange(nextX, nextY)) {
                    int currDist = weight + maze[nextY][nextX];

                    if (currDist < dist[nextY][nextX]) {
                        dist[nextY][nextX] = currDist;
                        pq.emplace(currDist, make_pair(nextX, nextY));
                    }
                }
            }
        }
    }

    return dist[dist.size() - 1][dist[0].size() - 1];
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> maze(M);
    for (int i = 0; i < M; ++i) {
        maze[i].resize(N);
        for (int j = 0; j < N; ++j) {
            scanf("%1d", &maze[i][j]);
        }
    }

    cout << solve(maze) << endl;
    return 0;
}