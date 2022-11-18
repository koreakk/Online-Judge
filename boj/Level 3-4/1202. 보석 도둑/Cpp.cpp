#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> jewel[300000];
ll bag[300000], N, K;
priority_queue<ll> pq;

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> jewel[i].first
            >> jewel[i].second;
    }
    for (int i = 0; i < K; ++i) {
        cin >> bag[i];
    }

    sort(jewel, jewel + N);
    sort(bag  , bag   + K);

    ll result = 0;
    for (int i = 0, j = 0; i < K; ++i) {
        for (; j < N && jewel[j].first <= bag[i]; ++j) {
            pq.push(jewel[j].second);
        }

        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}