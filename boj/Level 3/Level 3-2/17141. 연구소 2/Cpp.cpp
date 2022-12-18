#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

constexpr int INF   = 100000000;
constexpr int dy[4] = { -1, 1, 0, 0 };
constexpr int dx[4] = { 0, 0, -1, 1 };

vector<vector<pii>> combinations(const vector<pii>& base, int r) {
    const int N = int(base.size());

    vector<vector<pii>> result;
    if (r > N) return result;

    auto Add = [&](const vector<int>& indices) {
        vector<pii> ret(r);
        for (int i = 0; i < r; ++i) {
            ret[i] = base[indices[i]];
        }

        result.emplace_back(ret);
    };

    vector<int> indices(r);
    for (int i = 0; i < r; ++i) {
        indices[i] = i; 
    }

    Add(indices);

    if (r == N) return result;

    while (true) {
        int i = -1;
        for (int j = r - 1; j >= 0; --j) {
            if (indices[j] != j + N - r) {
                i = j;
                break;
            }
        }
        if (i == -1) { break; }

        ++indices[i];
        for (int j = i + 1; j < r; ++j) {
            indices[j] = indices[j - 1] + 1;
        }
        Add(indices);
    }

    return result;
}

int N, M, A[50][50], V[50][50];

bool inRange(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

int bfs(const vector<pii>& info) {
    memset(V, 0, sizeof(V));

    queue<pii> q;
    for (auto [y, x] : info) {
        q.emplace(y, x);
        V[y][x] = 1;
    }

    int cnt = 0;
    for (; !q.empty(); ++cnt) {
        int size = int(q.size());

        for (int i = 0; i < size; ++i) {
            auto [y, x] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (!inRange(ny, nx) || A[ny][nx] || V[ny][nx]) {
                    continue;
                }

                V[ny][nx] = 1;
                q.emplace(ny, nx);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == 0 && V[i][j] == 0) {
                return INF;
            }
        }
    }
    return cnt - 1;
}

void solve() {
    cin >> N >> M;

    vector<pii> info;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];

            if (A[i][j] == 2) {
                info.emplace_back(i, j);
                A[i][j] = 0;
            }
        }
    }

    int ret = INF;
    for (const auto& x : combinations(info, M)) {
        ret = min(ret, bfs(x));
    }

    ret = ret >= INF ? -1 : ret;
    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
