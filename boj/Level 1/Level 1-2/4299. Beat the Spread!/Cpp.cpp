#include <iostream>
using namespace std;

int N, arr[100001];

void solve() {
    int a, b;
    cin >> a >> b;

    int x = (a + b) / 2;
    int y = (a - b) / 2;
    if (x < y) swap(x, y);

    if (y < 0 || x + y != a)
        cout << -1;
    else cout << x << ' ' << y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}