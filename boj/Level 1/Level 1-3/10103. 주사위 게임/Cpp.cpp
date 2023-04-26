#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int p1 = 100, p2 = 100;
    for (int i=0; i<n; ++i) {
        int s1, s2;
        cin >> s1 >> s2;

        if      (s1 < s2) { p1 -= s2; }
        else if (s1 > s2) { p2 -= s1; }
    }

    cout << p1 << '\n' << p2 << '\n';
    return 0;
}
