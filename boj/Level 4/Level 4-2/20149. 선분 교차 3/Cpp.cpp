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
        if (e1 <= s1) { swap(s1, e1); }
        if (e2 <= s2) { swap(s2, e2); }

        if (s1 <= e2 && s2 <= e1) {
            cout << "1\n";

            if (s1.x == e2.x) {
                cout << s1.x << ' ' << s1.y << endl;
            }
            else if (e1.x == s2.x) {
                cout << e1.x << ' ' << e1.y << endl;
            }
        }
        else {
            cout << "0\n";
        }
    }
    else if(ccw(s2, e2, s1) != ccw(s2, e2, e1) && d1 != d2){
        cout << "1\n";

        if ((s1.x == e1.x || s2.x == e2.x) && (s1.y == e1.y || s2.y == e2.y)) {
            if (s1.x == e1.x) {
                cout << s1.x << ' ' << s2.y << endl;
            }
            else {
                cout << s2.x << ' ' << s1.y << endl;
            }
            return;
        }

        bool isRotate = false;
        if (s1.x == e1.x || s2.x == e2.x) {
            swap(s1.x, s1.y); swap(e1.x, e1.y);
            swap(s2.x, s2.y); swap(e2.x, e2.y);
            isRotate = true;
        }

        double A1 = (double)(e1.y - s1.y) / (e1.x - s1.x);
        double B1 = s1.y - (A1 * s1.x);

        double A2 = (double)(e2.y - s2.y) / (e2.x - s2.x);
        double B2 = s2.y - (A2 * s2.x);

        double A = (B2 - B1) / (A1 - A2);
        double B = (A * A1) + B1;

        if (isRotate) { swap(A, B); }
        cout << A << ' ' << B << endl;
    }
    else {
        cout << "0\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(16);
    solve();
    return 0;
}