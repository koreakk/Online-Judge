#include <bits/stdc++.h>
using namespace std;

int main(void) {
    array<int, 4> pos_info;
    int x, y, r;
    for (auto &n : pos_info) {
        cin >> n;
    }
    cin >> x >> y >> r;
    
    int result(0);
    for (int i = 0; i < 4; ++i) {
        if (pos_info[i] == x) {
            result = i + 1;
        }
    }
    
    cout << result;
    return 0;
}