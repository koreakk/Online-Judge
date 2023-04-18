#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(2);

    int t;
    cin >> t;

    double n;
    string s;

    while (t--) {
        cin >> n;
        getline(cin, s);

        for (char c : s) {
            switch (c) {
                case '@': { n*=3; break; }
                case '%': { n+=5; break; }
                case '#': { n-=7; break; }
                default:  {       break; }
            }
        }

        cout << n << '\n';
    }

    return 0;
}
