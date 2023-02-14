#include <bits/stdc++.h>
using namespace std; 

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> matA(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matA[i][j];
        }
    }

    int M2, K;
    cin >> M2 >> K;

    vector<vector<int>> matB(M2, vector<int>(K, 0));
    for (int i = 0; i < M2; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> matB[i][j];
        }
    }

    vector<vector<int>> ret(N, vector<int>(K, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < M; ++k) {
                ret[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cout << ret[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
