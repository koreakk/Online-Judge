#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    int A[100], n;

    while (t--) {
        cin >> n;
        for_each(A, A+n, [](int& p) { cin >> p; });

        cout << (*max_element(A, A+n) - *min_element(A, A+n)) * 2 << '\n';
    }

    return 0;
}
