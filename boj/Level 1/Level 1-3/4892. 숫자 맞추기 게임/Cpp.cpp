#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, i=1;

    for (;; ++i) {
        cin >> n;
        if (n == 0) { break; }

        if (n & 1) {
            cout << i << ". odd " << (3*n+1)/6 << '\n';
        }
        else {
            cout << i << ". even " << n/2 << '\n';
        }
    }

    return 0;
}
