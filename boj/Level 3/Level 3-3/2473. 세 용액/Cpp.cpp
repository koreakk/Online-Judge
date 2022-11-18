#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

int N;
ll arr[5000];

pll f(ll t, int s, int e) {
    int l = s, r = e;
    ll resl = arr[l], resr = arr[r];
    while (l < r) {
        ll x = arr[l] + arr[r] + t;

        if (std::abs(resl + resr + t) > std::abs(x)) {
            resl = arr[l], resr = arr[r];
        }

        if (x < 0) ++l;
        else       --r;
    }

    return { resl, resr };
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    ll l = arr[1], r = arr[2], k = arr[0];
    for (int i = 0; i < N - 2; ++i) {
        auto [curL, curR] = f(arr[i], i + 1, N - 1);
        if (std::abs(l + r + k) > std::abs(curL + curR + arr[i])) {
            l = curL, r = curR, k = arr[i];
        }
    }

    cout << k << ' ' << l << ' ' << r << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}