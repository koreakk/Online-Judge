#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

using position_type = pair<int, int>;
using node_type     = pair<int, position_type>;
using pq_type       = priority_queue<node_type, vector<node_type>, greater<node_type>>;
using distance_type = vector<vector<int>>;

char graph[105][105];

distance_type Dijkstra(int h, int w, int x, int y) {
    auto InRange = [&](int x, int y) {
        return x >= 0 && x < w && y >= 0 && y < h;
    };

    const int dx[4] = { 1, 0, -1, 0 };
    const int dy[4] = { 0, 1, 0, -1 };

    distance_type distance(h + 1);
    for (int i = 0; i < h; ++i) {
        distance[i].resize(w + 1, -1);
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

            if (!InRange(nextX, nextY) || graph[nextY][nextX] == '*') {
                continue;
            }

            int currDist = weight + static_cast<int>(graph[nextY][nextX] == '#');
            if (distance[nextY][nextX] == -1 || currDist < distance[nextY][nextX]) {
                distance[nextY][nextX] = currDist;
                pq.emplace(currDist, make_pair(nextX, nextY));
            }
        }
    }

    return distance;
}

pair<position_type, position_type> FindPrisonerPosition(int h, int w) {
    pair<position_type, position_type> res;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (graph[i][j] == '$') {
                if (res.first.first != 0 || res.first.second != 0) {
                    res.second = make_pair(j, i);
                }
                else {
                    res.first = make_pair(j, i);
                }
            }
        }
    }

    return res;
}

int solve() {
    memset(graph, 0x00, sizeof(graph));

    int h, w;
    cin >> h >> w;

    for (int i = 1; i <= h; ++i) {
        cin >> graph[i] + 1;
    }
    h += 2, w += 2;

    const auto&& [prisoner1, prisoner2] = FindPrisonerPosition(h, w);
    const auto&  [x1, y1] = prisoner1;
    const auto&  [x2, y2] = prisoner2;

    auto&& dist1 = Dijkstra(h, w, x1, y1);
    auto&& dist2 = Dijkstra(h, w, x2, y2);
    auto&& dist3 = Dijkstra(h, w,  0,  0);
    
    int result = INT_MAX;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (graph[i][j] != '*') {
                int d1 = dist1[i][j];
                int d2 = dist2[i][j];
                int d3 = dist3[i][j];

                if (d1 != -1 && d2 != -1 && d3 != -1) {
                    result = min(
                        result,
                        d1 + d2 + d3 - (graph[i][j] == '#' ? 2 : 0)
                    );
                }
            }
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        cout << solve() << endl;
    }

    return 0;
}
