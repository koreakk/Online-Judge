#include <iostream>
using namespace std;

bool board[3072][6143];
void solve(int x, int y, int n) {
    if (n == 3) {
        board[y][x]         = true;
        board[y + 1][x - 1] = true;
        board[y + 1][x + 1] = true;
        for (int i = x - 2; i <= x + 2; ++i)
            board[y + 2][i] = true;

        return;
    }
    solve(x, y, n / 2);
    solve(x - n / 2, y + n / 2, n / 2);
    solve(x + n / 2, y + n / 2, n / 2);
}


int main() {
    int N;
    cin >> N;

    solve(N - 1, 0, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j) {
            cout << (board[i][j] ? '*' : ' ');
        }
        cout << endl;
    }
    return 0;
}