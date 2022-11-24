#include <bits/stdc++.h>
using namespace std;

struct Point { int l, r; };

bool operator<(const Point& l, const Point& r) {
    if (l.l == r.l) { return l.r > r.r; }
    return l.l < r.l;
}

bool operator==(const Point& l, const Point& r) {
    return l.l == r.l && l.r == r.r;
}

void solve() {
    int N; cin >> N;

    vector<Point> P(N);
    for (auto& [l, r] : P) {
        int n;
        cin >> n >> l >> r;
    }

    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());

    vector<int> L = { 0 };
    L.reserve(P.size());

    int ret = 1;
    for (const auto& [l, r] : P) {
        if (L.back() >= r) {
            L.push_back(r);
            ++ret;
        }
        else {
            *upper_bound(L.begin(), L.end(), r, greater<>()) = r;
        }
    }

    cout << ret << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}