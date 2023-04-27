#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, y, k;
    cin >> t;

    for (int i=0; i<t; ++i) {
        n = 0;

        for (int j=0; j<9; ++j) {
            cin >> y >> k;
            n += y-k;
        }

        if (n > 0)      { cout << "Yonsei\n"; }
        else if (n < 0) { cout << "Korea\n";  }
        else            { cout << "Draw\n";   }
    }

    return 0;
}
