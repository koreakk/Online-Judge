#include <iostream>
#include <memory>
using namespace std;

void solve() {
    long long lt, wt, le, we;
    cin >> lt >> wt >> le >> we;

    long long x = lt * wt - le * we;
    if (x == 0) {
        cout << "Tie\n";
    }
    else if (x > 0) {
        cout << "TelecomParisTech\n";
    }
    else {
        cout << "Eurecom\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}