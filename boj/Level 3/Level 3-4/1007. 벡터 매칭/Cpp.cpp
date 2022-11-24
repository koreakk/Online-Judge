#include <bits/stdc++.h>
using namespace std;

constexpr double INF = 1e10;

struct Point { int x, y; };

int N;
Point P[20];

double f(int i, int c, int v) {
    if (c == 0) {
        double x = 0, y = 0;
        for (int i = 0; i < N; ++i) {
            if (v & (1 << i)) {
                x += (double)P[i].x;
                y += (double)P[i].y;
            }
            else {
                x -= (double)P[i].x;
                y -= (double)P[i].y;
            }
        }
        
        return sqrt(x * x + y * y);
    }

    double ret = INF;
    for (; i < N; ++i) {
        if (!(v & (1 << i))) {
            ret = min(ret, f(i + 1, c - 1, v | (1 << i)));
        }
    }

    return ret;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> P[i].x >> P[i].y;
    }

    cout << f(0, N / 2, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(12);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}