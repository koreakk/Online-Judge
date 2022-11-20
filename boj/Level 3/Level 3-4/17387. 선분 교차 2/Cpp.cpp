#include <bits/stdc++.h>
using namespace std;

struct Point { long long x, y; };

bool operator<=(const Point& left, const Point& right) {
    if (left.x == right.x) {
        return left.y <= right.y;
    }
    return left.x <= right.x;
}

int ccw(const Point& p1, const Point& p2, const Point& p3) {
    long long d = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return (d > 0) ? 1 : (d < 0) ? -1 : 0;
}

void solve() {
    Point s1, e1, s2, e2;
    cin >> s1.x >> s1.y >> e1.x >> e1.y;
    cin >> s2.x >> s2.y >> e2.x >> e2.y;

    int d1 = ccw(s1, e1, s2), d2 = ccw(s1, e1, e2);
    if (d1 == 0 && d2 == 0) {
        if (e1 <= s1) swap(s1, e1);
        if (e2 <= s2) swap(s2, e2);

        cout << (int)(s1 <= e2 && s2 <= e1) << endl;
    }
    else {
        cout << (int)(ccw(s2, e2, s1) != ccw(s2, e2, e1) && d1 != d2) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}