#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 100000000000ll;

ll dist[301][301];
int N, M, S, T, Q;

void solve() {
    cin >> N >> M >> S >> T;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i != j) dist[i][j] = INF;
        }
    }

    int u, v, w;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> w;
        if (dist[u][v] > w) {
            dist[u][v] = (ll)w;
        }
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cin >> Q;
    int a1, b1, c1, a2, b2, c2;
    for (int i = 0; i < Q; ++i) {
        cin >> a1 >> b1 >> c1;
        cin >> a2 >> b2 >> c2;

        ll t1 = dist[a1][b1];
        ll t2 = dist[a2][b2];

        dist[a1][b1] = min(dist[a1][b1], (ll)c1);
        dist[a2][b2] = min(dist[a2][b2], (ll)c2);

        ll ret = dist[S][T];
        ret = min(ret, dist[S][a1] + dist[a1][b1] + dist[b1][T]);
        ret = min(ret, dist[S][a2] + dist[a2][b2] + dist[b2][T]);
        ret = min(ret, dist[S][a1] + dist[a1][b1] + dist[b1][a2] + dist[a2][b2] + dist[b2][T]);
        ret = min(ret, dist[S][a2] + dist[a2][b2] + dist[b2][a1] + dist[a1][b1] + dist[b1][T]);

        dist[a1][b1] = t1;
        dist[a2][b2] = t2;

        if (ret >= INF) {
            cout << -1 << '\n';
            continue;
        }
        cout << ret << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}