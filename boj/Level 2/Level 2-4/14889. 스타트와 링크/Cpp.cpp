#include <bits/stdc++.h>
using namespace std;

int N, A[20][20];
int V[20];
int ret = INT_MAX;

void f(int i, int s) {    
    if (i == N / 2) {
        int diff = 0;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (V[i] != V[j]) { continue; }

                if (V[i]) { diff += A[i][j]; }
                else      { diff -= A[i][j]; }
            }
        }
        
        ret = min(ret, abs(diff));
        return;
    }
    
    for (int n = s; n < N; ++n) {
        if (V[n]) { continue; }

        V[n] = 1;
        f(i + 1, n + 1);
        V[n] = 0;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    f(0, 0);

    cout << ret << '\n';
    return 0;
}
