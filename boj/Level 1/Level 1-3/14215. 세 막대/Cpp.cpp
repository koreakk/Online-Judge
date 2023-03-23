#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (b < c) { swap(b, c); }
    if (a < b) { swap(a, b); }

    cout << b+c+min(a,b+c-1) << '\n';
    return 0;
}
