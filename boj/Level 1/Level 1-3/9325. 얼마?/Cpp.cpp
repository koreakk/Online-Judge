#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int s;
        cin >> s;

        int n;
        cin >> n;

        while (n--) {
            int p, q;
            cin >> p >> q;

            s += p*q;
        }

        cout << s << '\n';
    }
    return 0;
}
