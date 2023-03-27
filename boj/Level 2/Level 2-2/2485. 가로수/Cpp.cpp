#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) { return b; }
    return gcd(b%a, a);
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n-1);
    int curr, prev;

    cin >> curr;
    for (int i = 0; i < n-1; ++i) {
        prev = curr;
        cin >> curr;

        v[i] = curr - prev;
    }

    int g = v[0];
    for (int i = 1; i < n-1; ++i) {
        g = gcd(g, v[i]);
    }

    int ret = 0;
    for (int i = 0; i < n-1; ++i) {
        ret += v[i]/g-1;
    }

    cout << ret << '\n';
    return 0;
}
