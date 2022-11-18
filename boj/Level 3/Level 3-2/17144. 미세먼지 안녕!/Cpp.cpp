#include <iostream>
#include <vector>   
using namespace std;

int R, C, T, board[51][51], Y;

void F1() {
    vector<pair<pair<int, int>, int>> S;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] >= 5) {
                S.emplace_back(make_pair(j, i), board[i][j] / 5);
            }
        }
    }

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    for (const auto& [pos, val] : S) {
        const auto& [x, y] = pos;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= C || ny < 0 || ny >= R) {
                continue;
            }

            if (board[ny][nx] == -1) {
                continue;
            }

            board[ny][nx] += val;
            board[y][x]   -= val;
        }
    }
}

void F2() {
    for (int y = Y - 2; y >= 0; --y) {
        board[y + 1][0] = board[y][0];
    }
    for (int x = 1; x < C; ++x) {
        board[0][x - 1] = board[0][x];
    }
    for (int y = 1; y <= Y; ++y) {
        board[y - 1][C - 1] = board[y][C - 1];
    }
    for (int x = C - 2; x >= 1; --x) {
        board[Y][x + 1] = board[Y][x];
    }
    board[Y][1] = 0;

    for (int y = Y + 3; y < R; ++y) {
        board[y - 1][0] = board[y][0];
    }
    for (int x = 1; x < C; ++x) {
        board[R - 1][x - 1] = board[R - 1][x];
    }
    for (int y = R - 2; y >= Y + 1; --y) {
        board[y + 1][C - 1] = board[y][C - 1];
    }
    for (int x = C - 2; x >= 1; --x) {
        board[Y + 1][x + 1] = board[Y + 1][x];
    }
    board[Y + 1][1] = 0;
}

void solve() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < R; ++i) {
        if (board[i][0] == -1) {
            Y = i;
            break;
        }
    }

    for (int i = 0; i < T; ++i) {
        F1();
        F2();
    }

    int result = 2;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            result += board[i][j];
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
