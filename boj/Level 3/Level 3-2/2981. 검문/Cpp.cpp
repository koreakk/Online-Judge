#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int v0 = v[0];
    for (int i = 0; i < n - 1; ++i) {
        v[i] -= v[i + 1];
    }
    v[n - 1] -= v0;

    int g = v[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, v[i]);
    }

    int i = 2;
    for (; i * i < g; ++i) {
        if (g % i == 0) { cout <<   i   << '\n'; }
    }

    if (i * i == g) { cout << i << '\n'; }

    for (; --i;) {
        if (g % i == 0) { cout << g / i << '\n'; }
    }

    return 0;
}
