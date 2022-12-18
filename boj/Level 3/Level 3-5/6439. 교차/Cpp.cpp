#include <bits/stdc++.h>
using namespace std;

struct Point { int   x, y; };
struct Line  { Point s, e; };

bool operator<=(const Point& left, const Point& right) {
    if (left.x == right.x) {
        return left.y <= right.y;
    }
    return left.x <= right.x;
}

int ccw(const Point& p1, const Point& p2, const Point& p3) {
    int d = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    return (d > 0) ? 1 : (d < 0) ? -1 : 0;
}

bool lineSegmentIntersection(const Line& Al, const Line& Bl) {
    Point s1 = Al.s, e1 = Al.e;
    Point s2 = Bl.s, e2 = Bl.e;

    int d1 = ccw(s1, e1, s2), d2 = ccw(s1, e1, e2);
    if (d1 == 0 && d2 == 0) {
        if (e1 <= s1) swap(s1, e1);
        if (e2 <= s2) swap(s2, e2);

        return s1 <= e2 && s2 <= e1;
    }

    return ccw(s2, e2, s1) != ccw(s2, e2, e1) && d1 != d2;
}

bool pointInRectangle(int x, int y, int lx, int ty, int rx, int by) {
    return lx <= x && rx >= x && ty >= y && by <= y;
}

void solve() {
    int sx, sy, ex, ey, lx, ty, rx, by;
    cin >> sx >> sy >> ex >> ey >> lx >> ty >> rx >> by;

    if (lx > rx) { swap(lx, rx); }
    if (by > ty) { swap(by, ty); }

    if (pointInRectangle(sx, sy, lx, ty, rx, by) ||
        pointInRectangle(ex, ey, lx, ty, rx, by))
    {
        cout << "T\n";
        return;
    }

    Line line{ {sx, sy}, {ex, ey} };

    Line l1{ {lx, ty}, {lx, by} };
    Line l2{ {rx, ty}, {rx, by} };
    Line l3{ {lx, ty}, {rx, ty} };
    Line l4{ {lx, by}, {rx, by} };

    for (const Line& l : { l1, l2, l3, l4 }) {
        if (lineSegmentIntersection(line, l)) {
            cout << "T\n";
            return;
        }
    }
    cout << "F\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) { solve(); }
    return 0;
}
