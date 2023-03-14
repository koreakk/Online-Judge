#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> v;

    for(;;) {
        cin >> n;
        if (n == -1) { break; }

        for (int i = 1; i*i <= n; ++i) {
            if (n%i == 0) {
                if (i*i == n) { v.push_back(i);   }

                else          { v.push_back(i);
                                v.push_back(n/i); }
            }
        }
        sort(v.begin(), v.end());

        int sum = 0;
        for (int i = 0; i < v.size()-1; ++i) {
            sum += v[i];
        }

        if (sum != n) {
            cout << n << " is NOT perfect.\n";
        }

        else {
            cout << n << " = " << v[0];
            for (int i = 1; i < v.size()-1; ++i) {
                cout << " + " << v[i];
            }
            cout << '\n';
        }

        v.clear();
    }

    return 0;
}
