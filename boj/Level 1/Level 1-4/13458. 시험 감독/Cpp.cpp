#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll A[1000000], N, B, C;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cin >> B >> C;

    ll ret = N;

    for (ll i = 0; i < N; ++i) {
        if (A[i] <= B) { continue; }
        
        ret += (A[i]-B+C-1) / C;
    }

   cout << ret << '\n';
   return 0;
}
