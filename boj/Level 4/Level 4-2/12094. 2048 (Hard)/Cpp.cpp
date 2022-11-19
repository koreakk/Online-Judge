#include <bits/stdc++.h>
using namespace std;

int N, A[20][20], maxScore;

void up() {
    for (int j = 0; j < N; ++j) {
        int val = -1, idx = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i][j] == 0) {
                continue;
            }

            if (A[i][j] == val) {
                A[idx][j] *= 2;
                val = -1;
            }
            else {
                val = A[i][j];
                A[++idx][j] = A[i][j];
            }
        }

        for (int i = idx + 1; i < N; ++i) {
            A[i][j] = 0;
        }
    }
}

void down() {
    for (int j = 0; j < N; ++j) {
        int val = -1, idx = N;
        for (int i = N - 1; i >= 0; --i) {
            if (A[i][j] == 0) {
                continue;
            }

            if (A[i][j] == val) {
                A[idx][j] *= 2;
                val = -1;
            }
            else {
                val = A[i][j];
                A[--idx][j] = A[i][j];
            }
        }

        for (int i = idx - 1; i >= 0; --i) {
            A[i][j] = 0;
        }
    }
}

void left() {
    for (int i = 0; i < N; ++i) {
        int val = -1, idx = -1;
        for (int j = 0; j < N; ++j) {
            if (A[i][j] == 0) {
                continue;
            }

            if (A[i][j] == val) {
                A[i][idx] *= 2;
                val = -1;
            }
            else {
                val = A[i][j];
                A[i][++idx] = A[i][j];
            }
        }

        for (int j = idx + 1; j < N; ++j) {
            A[i][j] = 0;
        }
    }
}

void right() {
    for (int i = 0; i < N; ++i) {
        int val = -1, idx = N;
        for (int j = N - 1; j >= 0; --j) {
            if (A[i][j] == 0) {
                continue;
            }

            if (A[i][j] == val) {
                A[i][idx] *= 2;
                val = -1;
            }
            else {
                val = A[i][j];
                A[i][--idx] = A[i][j];
            }
        }

        for (int j = idx - 1; j >= 0; --j) {
            A[i][j] = 0;
        }
    }
}

int score() {
    int x = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            x = max(x, A[i][j]);
        }
    }
    return x;
}

void f(int i) {
    int curScore = score();
    if (maxScore >= (1 << i) * curScore) {
        return;
    }

    maxScore = max(maxScore, curScore);
    if (i == 0) {
        return;
    }
    
    int t[20][20];
    memcpy(t, A, sizeof(A));

    for (auto move : { up, down, left, right }) {
        move();
        if (!memcmp(A, t, sizeof(t))) {
            continue;
        }

        f(i - 1);
        memcpy(A, t, sizeof(A));
    }
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    
    f(10);
    cout << maxScore << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}