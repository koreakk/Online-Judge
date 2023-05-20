#include <bits/stdc++.h>
using namespace std;

int main() {
    int s(0), m(INT_MAX);
    for (int i=0; i<7; ++i) {
        int n;
        cin >> n;
        if (n&1) { 
            m=min(m, n);
            s+=n;
        }
    }
    if (s==0) {
        cout << "-1\n";
    }
    else {
        cout << s << '\n' << m << '\n';
    }
    return 0;
}
