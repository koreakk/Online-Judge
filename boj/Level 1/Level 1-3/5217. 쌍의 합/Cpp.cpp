#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        cout << "Pairs for " << n << ": ";
        if (n<=2) { cout << "\n"; continue; }

        for (int i=1;;) {
            cout << i << " " << n-i; ++i;
            if (i>=n-i) { break; }
            cout << ", ";
        }
        cout << "\n";
    }

    return 0;
}
