#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r1=0, r2=INT_MAX, n;
        for (int i=0; i<7; ++i) {
            cin >> n;
            if (!(n&1)) {
                r1+=n;
                r2=min(r2, n);
            }
        }
        printf("%d %d\n", r1, r2);
    }
    return 0;
}
