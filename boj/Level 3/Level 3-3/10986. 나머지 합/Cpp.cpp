#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll A[1000], N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    ll ret = 0;
    ll n = 0, j = 0;

    for (int i = 0; i < N; ++i) {
        cin >> n;

        j = (j + (n % M)) % M;
        ++A[j];
    }

    ret += A[0];
    for (int i = 0; i < M; ++i) {
        ret += (A[i]) * (A[i]-1) / 2;
    }

    cout << ret << '\n';
    return 0;
}
