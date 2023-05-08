#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min(a, min(b, c)) + min(d, e) - 50 << '\n';
    return 0;
}
