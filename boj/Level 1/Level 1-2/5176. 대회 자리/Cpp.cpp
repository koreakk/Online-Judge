#include <bits/stdc++.h>
using namespace std;

int A[501];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p, m, n, ret=0;
        cin >> p >> m;
        fill(A, A+m+1, 0);
        while (p--) {
            cin >> n;
            if (A[n]) {
                ++ret;
            }
            A[n]=1;
        }
        cout << ret << '\n';
    }
    return 0;
}
