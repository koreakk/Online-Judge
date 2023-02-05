#include <bits/stdc++.h>
using namespace std;

int f(int n, int r) {
    int ret = 0;
    for (n /= r; n; n /= r) {
        ret += n;
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;

    int r1 = f(n, 5) - f(m, 5) - f(n - m, 5);
    int r2 = f(n, 2) - f(m, 2) - f(n - m, 2);

    cout << min(r1, r2);
    return 0;
}
