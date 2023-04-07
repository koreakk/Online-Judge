#include <bits/stdc++.h>
using namespace std;

unsigned long long fac(int n) {
    return (n == 0) ? 1ull : fac(n-1) * n;
}

int main() {
    int n;
    cin >> n;
    cout << fac(n) << endl;
    return 0;
}
