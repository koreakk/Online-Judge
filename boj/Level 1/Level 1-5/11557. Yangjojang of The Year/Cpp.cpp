#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; ++i) {
        string cur_s;
        int cur_l=0;

        int n;
        cin >> n;

        for (int j=0; j<n; ++j) {
            string s;
            int l;
            cin >> s >> l;

            if (l > cur_l) {
                cur_l = l;
                cur_s = s;
            }
        }

        cout << cur_s << '\n';
    }
}
