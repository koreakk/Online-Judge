#include <bits/stdc++.h>
using namespace std;

int A[1000][5], B[5][11][1000], C[1000][1000], N;
int main() {
    cin >> N;

    int k;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<5; ++j) {
            cin >> k;
            A[i][j]=k;
            B[j][k][i]=1;
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<5; ++j) {
            for (int k=0; k<N; ++k) {
                C[i][k]+=B[j][A[i][j]][k];
            }
        }
    }

    int ret=1, mx=0;
    for (int i=0; i<N; ++i) {
        int cr=0;
        for (int j=0; j<N; ++j) {
            if (C[i][j]) {
                ++cr;
            }
        }

        if (cr > mx) {
            ret=i+1;
            mx=cr;
        }
    }

    cout << ret << '\n';
    return 0;
}
