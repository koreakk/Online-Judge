#include <iostream>
#include <algorithm>
using namespace std;

int board[9][9], v[27][10], N;
pair<int, int> info[81];

#define CHECK1(x, y, n) (v[(x) / 3 * 3 + (y) / 3][n])
#define CHECK2(x, y, n) (v[(x) + 9][n])
#define CHECK3(x, y, n) (v[(y) + 18][n])

bool dfs(int s) {
    if (s >= N) return true;

    auto [x, y] = info[s];

    for (int i = 1; i <= 9; ++i) {
        if (CHECK1(x, y, i) || CHECK2(x, y, i) || CHECK3(x, y, i)) {
            continue;
        }
        CHECK1(x, y, i) = 1;
        CHECK2(x, y, i) = 1;
        CHECK3(x, y, i) = 1;

        board[y][x] = i;
        if (dfs(s + 1)) return true;

        CHECK1(x, y, i) = 0;
        CHECK2(x, y, i) = 0;
        CHECK3(x, y, i) = 0;
    }
    
    return false;
}

void solve() {
    char input[10];
    for (int i = 0; i < 9; ++i) {
        cin >> input;
        for (int j = 0; j < 9; ++j) {
            board[i][j] = input[j] - '0';
            if (board[i][j] == 0) {
                info[N++] = make_pair(j, i);
            }
            else {
                CHECK1(j, i, board[i][j]) = 1;
                CHECK2(j, i, board[i][j]) = 1;
                CHECK3(j, i, board[i][j]) = 1;
            }
        }
    }

    dfs(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}