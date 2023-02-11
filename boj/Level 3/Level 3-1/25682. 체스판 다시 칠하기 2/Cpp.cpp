#include <bits/stdc++.h>
using namespace std;

int A[2001][2001], N, M, K;

int main() {
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char ch;
            cin >> ch;
            
            if (((int)(ch == 'B') + i + j) & 1) { 
                A[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            A[i][j] += A[i][j-1];
        }
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            A[i][j] += A[i-1][j];
        }
    }

    int kk  = K * K;
    int ret = INT_MAX;

    for (int i = K; i <= N; ++i) {
        for (int j = K; j <= M; ++j) {
            int val = A[i][j] - A[i-K][j] - A[i][j-K] + A[i-K][j-K];
            ret = min(ret, min(val, kk - val));
        }
    }

    cout << ret << '\n';
    return 0;
}
