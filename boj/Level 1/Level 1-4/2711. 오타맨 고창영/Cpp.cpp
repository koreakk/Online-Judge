#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string str;

        cin >> n >> str;

        for (int i = 0; i < str.length(); ++i) {
            if (i+1 == n) { continue; }
            cout << str[i];
        }
        cout << '\n';
    }

    return 0;
}
