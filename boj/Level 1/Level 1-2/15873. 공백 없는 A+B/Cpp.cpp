#include <bits/stdc++.h>
using namespace std;

void solve() {
    char x[5];
    cin >> x;

    int A, B;
    if (x[1] == '0') {
        A = 10;
        B = (x[3] == '0') ? 10 : x[2] - '0';
    }
    else {
        A = x[0] - '0';
        B = (x[2] == '0') ? 10 : x[1] - '0';
    }

    cout << A + B;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(10);
    solve();
    return 0;
}
