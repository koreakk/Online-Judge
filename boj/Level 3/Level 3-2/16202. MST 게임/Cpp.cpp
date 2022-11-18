#include <iostream>
#include <vector>   
using namespace std;

int FindParent(vector<int>& parents, int v) {
    if (parents[v] == v) return v;
    return parents[v] = FindParent(parents, parents[v]);
}

void UnionParent(vector<int>& parents, int v, int u) {
    v = FindParent(parents, v);
    u = FindParent(parents, u);
    if (v < u) parents[u] = v;
    else parents[v] = u;
}

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int>> edges(M);
    for (auto& edge : edges) {
        cin >> edge.first >>
               edge.second;
    }

    int answer = 0;
    vector<int> parents(N + 1);

    for (int i = 0; i < K; ++i) {
        for (int j = 1; j <= N; ++j) {
            parents[j] = j;
        }
        answer = 0;

        for (int j = i; j < M; ++j) {
            auto [v, u] = edges[j];

            if (FindParent(parents, v) != FindParent(parents, u)) {
                UnionParent(parents, v, u);
                answer += j + 1;
            }
        }

        for (int j = 2, r = FindParent(parents, 1); j <= N; ++j) {
            if (FindParent(parents, j) != r) {
                answer = 0;
                break;
            }
        }
        cout << answer << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
