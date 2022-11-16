#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

ll T, N, M;
vector<ll> A, B;

void f(vector<ll>& v, ll n) {
    for (int i = 0; i < n; ++i) {
        ll x = v[i];
        for (int j = i + 1; j < n; ++j) {
            x += v[j];
            v.push_back(x);
        }
    }
}

void solve() {
    cin >> T;

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    cin >> M;
    B.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    f(A, N); f(B, M);
    sort(B.begin(), B.end());

    ll result = 0;
    for (int i = 0; i < A.size(); ++i) {
        ll t = T - A[i];

        result += (ll)(upper_bound(B.begin(), B.end(), t) -
                       lower_bound(B.begin(), B.end(), t));
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}