#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c = 0;

    for (int i = 1; i <= 5; ++i) {
        int c1, c2, c3, c4;
        cin >> c1 >> c2 >> c3 >> c4;

        if (c1+c2+c3+c4 > c) {
            c = c1+c2+c3+c4;
            n = i;
        }
    }

    cout << n << ' ' << c << '\n';
    return 0;
}
