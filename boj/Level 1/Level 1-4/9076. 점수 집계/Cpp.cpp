#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, A[5];
    cin >> t;

    while (t--) {
        cin >> A[0] >> A[1] >>
               A[2] >> A[3] >> A[4];

        sort(A, A+5);

        if (A[3]-A[1] >= 4) {
            cout << "KIN\n";
        }
        else {
            cout << A[1]+A[2]+A[3] << '\n';
        }
    }

    return 0;
}
