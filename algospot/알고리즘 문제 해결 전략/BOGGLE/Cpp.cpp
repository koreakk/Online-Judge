#include <bits/stdc++.h>
using namespace std;

char board[5][5], dp[5][5][10];

bool inRange(int y, int x) { return y >= 0 && y < 5 && x >= 0 && x < 5; }

bool dfs(int y, int x, const char* word, int i) {
    const int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
    const int dy[8] = { -1, 1, 0, 0, 1, -1, -1, 1 };

    if ( word[i] == '\0'        ) { return true;        } 
    if ( dp[y][x][i] != -1      ) { return dp[y][x][i]; }
    if ( board[y][x] != word[i] ) { return false;       }

    for (int direction = 0; direction < 8; ++direction) {
        int nextX = x + dx[direction];
        int nextY = y + dy[direction];

        if ( !inRange(nextY, nextX) ) { continue; }
        if ( dfs(nextY, nextX, word, i + 1) ) {
            dp[y][x][i] = 1;
            return dp[y][x][i];
        }
    }
    dp[y][x][i] = 0;
    return dp[y][x][i];
}

bool hasWord(const char* word) {
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (dfs(i, j, word, 0)) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> board[i][j];
        }
    }

    char word[11] = { 0 };
    int N; cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> word;
        cout << word << ' ';
        cout << (hasWord(word) ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}