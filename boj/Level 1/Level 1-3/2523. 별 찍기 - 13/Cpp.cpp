#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i=1; i<=n+n-1; ++i) {
        for (int j=min(i,n+n-i); j>=1; --j) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
