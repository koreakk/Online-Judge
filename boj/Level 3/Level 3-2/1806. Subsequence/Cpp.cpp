#include <iostream>
using namespace std;

int n, s, a[100000];

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int l = 0, sum = 0, res = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];

        while (sum - a[l] >= s) {
            sum -= a[l++];
        }

        if (sum >= s && (res == 0 || res > r - l)) {
            res = r - l + 1;
        }
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}