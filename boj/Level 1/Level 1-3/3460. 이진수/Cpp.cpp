#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i=0; i<32; ++i) {
            if (n & (1<<i)) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}
