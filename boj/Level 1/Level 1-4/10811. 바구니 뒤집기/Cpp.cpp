#include <bits/stdc++.h>
using namespace std;

int A[100], N, M;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        A[i] = i+1;
    }

    while (M--) {
        int i, j;
        cin >> i >> j;

        for (--i; i < --j; ++i) {
            swap(A[i], A[j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << A[i] << ' ';
    }
    cout << '\n';

    return 0;
}