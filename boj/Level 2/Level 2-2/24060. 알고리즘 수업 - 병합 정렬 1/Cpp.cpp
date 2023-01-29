#include <bits/stdc++.h>
using namespace std;

int A[500000], T[500000];
int N, K, R = -1;

void merge_sort(int l, int r) {
    if (l >= r) { return; }

    int m = l + (r - l) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);

    int i = l, j = m + 1, t = 0;
    while (i <= m && j <= r) {
        if (A[i] < A[j]) { T[t++] = A[i++]; }
        else             { T[t++] = A[j++]; }
    }

    while (i <= m) { T[t++] = A[i++]; }
    while (j <= r) { T[t++] = A[j++]; }

    t = 0, i = l;
    for (; i <= r; ++t, ++i) {
        A[i] = T[t];

        if (--K == 0) { R = A[i]; }
    }
}

void solve() {
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    merge_sort(0, N - 1);
    cout << R << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}