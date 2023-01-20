#include <bits/stdc++.h>
using namespace std;

const char * A[] = { "Soongsil\n", "Korea\n", "Hanyang\n" };

void solve() {
    int I[3];
    cin >> I[0] >>  I[1] >> I[2];

    if (I[0] + I[1] + I[2] >= 100) {
        cout << "OK\n";
        return;
    }

    int i = 0;
    for (int j = 1; j < 3; ++j) {
        if (I[i] > I[j]) { i = j; }
    }

    cout << A[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}