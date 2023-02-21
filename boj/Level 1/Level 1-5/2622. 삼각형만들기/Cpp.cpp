#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ret = 0;
    for (int i = n/3; i >= 1; --i) {
        for (int j = i; j <= n-i-j; ++j) {
            if (i+j > n-i-j) { ++ret; }
        }
    }

    cout << ret << '\n';
    return 0;
}
