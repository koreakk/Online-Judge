#include <bits/stdc++.h>
using namespace std;

int main() {
    int ret = 0;
    
    int cur = 0;

    for (int i = 0; i < 10; ++i) {
        int a, b;
        cin >> a >> b;

        cur += b - a;
        ret = max(ret, cur);
    }

    cout << ret << '\n';
    return 0;
}
