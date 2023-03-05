#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 2*n-1; i > 0; --i) {
        for (int j = abs(n-i); j > 0; --j) {
            cout << ' ';
        }
        for (int j = n-abs(n-i); j > 0; --j) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}