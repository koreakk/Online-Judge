#include <bits/stdc++.h>
using namespace std;

int main() {
    int i=0, ret=0, p, t;
    cin >> t;
    while (t--) {
        cin >> p;
        if (p) { ret+=(++i); }
        else   { i=0;        }
    }
    cout << ret << '\n';
    return 0;
}
