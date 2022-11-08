#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, board[101][101], visited[101][101];

void bfs() {
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                continue;
            }

            if (board[ny][nx] == 1) {
                visited[ny][nx] += 1;
                continue;
            }

            if (!visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.emplace(nx, ny);
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    queue<pair<int, int>> cheese;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            
            if (board[i][j] == 1) {
                cheese.emplace(j, i);
            }
        }
    }

    int result = 0;
    for (; !cheese.empty(); ++result) {
        bfs();
        
        int size = (int)cheese.size();
        for (int i = 0; i < size; ++i) {
            auto [x, y] = cheese.front();
            cheese.pop();

            if (visited[y][x] >= 2) {
                board[y][x] = 0;
            }
            else {
                cheese.emplace(x, y);
            }
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
