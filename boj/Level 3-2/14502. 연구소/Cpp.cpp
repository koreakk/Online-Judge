#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> combinations(const vector<pair<int, int>>& base, int r) {
    const int n = (int)base.size();

    vector<vector<pair<int, int>>> result;
    if (r > n) return result;

    auto Add = [&](const vector<int>& indices) {
        vector<pair<int, int>> res;
        for (int i : indices) {
            res.emplace_back(base[i]);
        }
        result.emplace_back(res);
    };

    vector<int> indices(r);
    for (int i = 0; i < r; ++i) { indices[i] = i; }
    Add(indices);
    if (r == n) return result;

    while (true) {
        int i = -1;
        for (int j = r - 1; j >= 0; --j) {
            if (indices[j] != j + n - r) {
                i = j;
                break;
            }
        }
        if (i == -1) break;

        ++indices[i];
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        Add(indices);
    }

    return result;
}

int board[8][8], visited[8][8], N, M;
void dfs(int x, int y) {
    visited[y][x] = 1;

    const int dx[] = { 0, 0, -1, 1 };
    const int dy[] = { -1, 1, 0, 0 };

    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) {
            continue;
        }

        if (board[nextY][nextX] == 0 && visited[nextY][nextX] == 0) {
            dfs(nextX, nextY);
        }
    }
}


int count() {
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 0 && visited[i][j] == 0) {
                ++answer;
            }
        }
    }
    return answer;
}

int solve() {
    vector<pair<int, int>> virusInfo;
    vector<pair<int, int>> blankInfo;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            switch (board[i][j])
            {
            case 0:
                blankInfo.emplace_back(j, i);
                break;
            case 2:
                virusInfo.emplace_back(j, i);
                break;
            default:
                break;
            }
        }
    }

    int answer = 0;
    for (const auto& blank : combinations(blankInfo, 3)) {
        for (auto [x, y] : blank) { board[y][x] = 1; }

        memset(visited, 0, sizeof(visited));
        for (auto [x, y] : virusInfo) {
            dfs(x, y);
        }
        answer = max(answer, count());
        
        for (auto [x, y] : blank) { board[y][x] = 0; }
    }

    return answer;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    cout << solve() << endl;
}