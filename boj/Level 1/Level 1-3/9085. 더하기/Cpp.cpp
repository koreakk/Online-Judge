#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, p, r;
    cin >> t;
    while (t--) {
        cin >> n;
        r=0;
        while (n--) {
            cin >> p;
            r+=p;
        }
        cout << r << '\n';
    }
    return 0;
}
