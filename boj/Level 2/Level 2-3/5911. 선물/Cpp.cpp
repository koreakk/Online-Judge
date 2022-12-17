#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, B;
pair<ll, ll> A[1000];

void solve() {
    cin >> N >> B;

    for (int i = 0; i < N; ++i) {
        ll p, s;
        cin >> p >> s;
        
        A[i] = make_pair(p + s, p / 2 + s);
    }

    sort(A, A + N);

    int ret = 0;
    for (int i = 0; i < N; ++i) {
        ll x = A[i].second;
        if (x > B) { continue; }

        ret = max(ret, 1);
        for (int j = 0; j < N; ++j) {
            if (i == j) { continue; }

            x += A[j].first;
            if (x > B) { break; }

            ret = max(ret, j + 1 + int(i > j));
        }
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}