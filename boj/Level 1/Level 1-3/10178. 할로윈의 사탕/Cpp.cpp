#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        printf("You get %d piece(s) and your dad gets %d piece(s).\n",
            a/b, a%b);
    }
    return 0;
}
