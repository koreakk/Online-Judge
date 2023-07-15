#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll n, r=0;
    cin >> n;
    for (; n != 1; ++r) {
        if (n & 1) { ++n; }
        else    { n /= 2; }
    }
    cout << r << '\n';
    return 0;
}