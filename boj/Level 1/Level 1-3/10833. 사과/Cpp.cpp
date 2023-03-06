#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ret = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;

        ret += b % a;
    }

    cout << ret << '\n';
    return 0;
}
