#include <bits/stdc++.h>
using namespace std;

int A[100], N, M;

int main () {
    cin >> N >> M;

    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;

        for (; i <= j; ++i) {
            A[i-1] = k;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';

    return 0;
}