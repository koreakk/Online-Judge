#include <iostream>
#include <cstring>
using namespace std;

int board[16][16], dp[16][16][3], N;
int dfs(int x, int y, int s) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 0;
    }

    if (board[y][x] || (s == 2 && (board[y][x - 1] || board[y - 1][x]))) {
        return 0;
    }

    if (x == N - 1 && y == N - 1) {
        return 1;
    }

    int& val = dp[y][x][s];
    if (val == -1) {
        switch (s)
        {
        case 0:
            val = dfs(x + 1, y, 0) +
                  dfs(x + 1, y + 1, 2);
            break;
        case 1:
            val = dfs(x, y + 1, 1) +
                  dfs(x + 1, y + 1, 2);
            break;
        case 2:
            val = dfs(x + 1, y, 0) +
                  dfs(x, y + 1, 1) +
                  dfs(x + 1, y + 1, 2);
            break;
        default:
            break;
        }
    }

    return dp[y][x][s];
}


int main() {
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(1, 0, 0) << endl;
    return 0;
}