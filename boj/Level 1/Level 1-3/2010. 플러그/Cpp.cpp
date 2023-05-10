#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    int ret=1;
    while (n--) {
        cin >> a;
        ret += a-1;
    }

    cout << ret << '\n';
    return 0;
}
