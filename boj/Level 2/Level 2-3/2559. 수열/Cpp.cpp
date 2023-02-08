#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        A[i] += A[i-1];
    }

    int ret = INT_MIN;
    for (int i = k; i <= n; ++i) {
        ret = max(ret, A[i] - A[i-k]);
    }

    cout << ret << '\n';
    return 0;
}
