#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;

    cout << (int)((double)(c*e-b*f)/(a*e-b*d))  << ' ';
    cout << (int)((double)(-c*d+a*f)/(a*e-b*d)) << '\n';

    return 0;
}
