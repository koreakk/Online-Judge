#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[1000][1000];
int  V[1000][1000];

int f(int y, int x, int k) {
    if (V[y][x]) { 
        return V[y][x] == k ? 1 : 0; 
    }
    V[y][x] = k;
    
    switch (A[y][x]) {
    case 'U': return f(y - 1, x, k);
    case 'D': return f(y + 1, x, k);
    case 'L': return f(y, x - 1, k);
    case 'R': return f(y, x + 1, k);
    default : return 0; 
    }
}

void solve() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }

    int k   = 0;
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!V[i][j]) {
                ret += f(i, j, ++k);
            }
        }
    }

    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}