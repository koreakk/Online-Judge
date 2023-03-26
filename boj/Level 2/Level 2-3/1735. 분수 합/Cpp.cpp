#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) { return b; }
    return gcd(b%a, a);
}

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    int a = (a1*b2 + a2*b1), b = (b1*b2);
    int g = gcd(a, b);

    cout << a/g << ' ' << b/g << '\n';
    return 0;
}
