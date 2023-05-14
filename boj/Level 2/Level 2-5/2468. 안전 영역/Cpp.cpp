#include <bits/stdc++.h>
using namespace std;

int G[100][100], D[100][100], N;

void dfs(int x, int y, int h) {
    const int dx[4] = { 1, -1, 0, 0 };
    const int dy[4] = { 0, 0, 1, -1 };

    D[x][y] = 1;
    for (int i=0; i<4; ++i) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (0>nx || N<=nx || 0>ny || N<=ny) {
            continue;
        }

        if (G[nx][ny]>h && !D[nx][ny]) {
            dfs(nx, ny, h);
        }
    }
}

int count(int h) {
    memset(D, 0, sizeof(D));

    int ret=0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (G[i][j]>h && !D[i][j]) {
                dfs(i, j, h);
                ++ret;
            }
        }
    }

    return ret;
}

int main() {
    int max_height=0;

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> G[i][j];
            max_height = max(max_height, G[i][j]);
        }
    }

    int ret=0;
    for (int h=0; h<=max_height; ++h) {
        ret = max(count(h), ret);
    }

    cout << ret << '\n';
    return 0;
}
