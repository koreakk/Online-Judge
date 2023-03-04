#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int    c_s = 0;
        double g_s = 0;

        while (n--) {
            int c; double g;
            cin >> c >> g;

            c_s += c;
            g_s += g*c;
        }

        cout << c_s << ' ' << g_s/c_s << '\n';
    }

    return 0;
}
