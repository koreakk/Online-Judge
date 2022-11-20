#include <bits/stdc++.h>
using namespace std;

struct Point { long long x, y; };

int ccw(Point p1, Point p2, Point p3) {
    long long d = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return (d > 0) ? 1 : (d < 0) ? -1 : 0;
}

void solve() {
    Point s1, e1, s2, e2;
    cin >> s1.x >> s1.y >> e1.x >> e1.y;
    cin >> s2.x >> s2.y >> e2.x >> e2.y;

    cout << (int)(ccw(s1, e1, s2) != ccw(s1, e1, e2) &&
                  ccw(s2, e2, s1) != ccw(s2, e2, e1)) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}