#include <bits/stdc++.h>
using namespace std;

int main() {
    int ret=0, cur=0;
    for (int i=0; i<4; ++i) {
        int l, r;
        cin >> l >> r;
        cur += r-l;
        ret = max(ret, cur);
    }
    cout << ret << '\n';
    return 0;
}
