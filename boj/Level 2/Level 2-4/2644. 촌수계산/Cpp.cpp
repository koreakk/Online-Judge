#include <bits/stdc++.h>
using namespace std;

int G[101][101], V[101], N;

int main() {
    int src, dst, m;

    cin >> N;
    cin >> src >> dst;
    cin >> m;

    for (int i=0; i<m; ++i) {
        int x, y;
        cin >> x >> y;

        G[x][y] = 1;
        G[y][x] = 1;
    }

    int ret = -1;
    queue<pair<int, int>> q;
    q.push(make_pair(src, 0));

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        int c = p.first;
        int w = p.second;

        if (c == dst) {
            ret = w;
            break;
        }

        if (V[c]) {
            continue;
        }
        V[c] = 1;

        for (int i=1; i<=N; ++i) {
            if (G[c][i] && !V[i]) {
                q.push(make_pair(i, w+1));
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
