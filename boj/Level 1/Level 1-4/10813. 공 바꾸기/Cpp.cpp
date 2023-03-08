#include <bits/stdc++.h>
using namespace std;

int A[100], N, M;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) { A[i] = i+1; }

    while (M--) {
        int i, j;
        cin >> i >> j;

        swap(A[i-1], A[j-1]);
    }

    for (int i = 0; i < N; ++i) { cout << A[i] << ' '; }
    cout << '\n';

    return 0;
}