#include <bits/stdc++.h>
using namespace std;

int N, M, K, A[100][100];

int dfs(int x, int y) {
    if (x<0 || x>=M || y<0 || y>=N || A[x][y]) {
        return 0;
    }

    A[x][y]=1;
    return dfs(x+1, y) + dfs(x-1, y) + \
           dfs(x, y+1) + dfs(x, y-1) + 1;
}

int main() {
    cin >> N >> M >> K;

    int sx, sy, ex, ey;
    for (int i=0; i<K; ++i) {
        cin >> sx >> sy >> ex >> ey;

        for (int x=sx; x<ex; ++x) {
            for (int y=sy; y<ey; ++y) {
                A[x][y]=1;
            }
        }
    }

    vector<int> ret;
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            if (A[i][j] == 0) {
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());

    cout << ret.size() << '\n';
    for (int p : ret) {
        cout << p << ' ';
    }
    cout << '\n';

    return 0;
}
