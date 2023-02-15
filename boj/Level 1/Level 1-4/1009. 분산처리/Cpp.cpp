#include <bits/stdc++.h>
using namespace std;

int A[100];

int main() {
    int t;
    cin >> t;

    for (;t--;) {
        int a, b;
        cin >> a >> b;

        int i = 1;
        A[0] = a % 10;
        
        for (;;) {
            int val = (A[i-1] * a) % 10;

            if (val == A[0]) { break; }
            A[i++] = val;
        }
        
        if (A[(b-1)%i] == 0) {
            cout << "10\n";
            continue;
        }
        cout << A[(b-1)%i] << '\n';
    }

    return 0;
}
