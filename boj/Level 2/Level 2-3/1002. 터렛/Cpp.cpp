#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x1, y1, r1;
    int x2, y2, r2;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    if (x1 == x2 && y1 == y2 && r1 == r2) {
        cout << "-1\n";
        return;
    }

    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y1);
        swap(r1, r2);
    }
    
    int dx = x1 - x2;
    int dy = y1 - y2;

    double dist = sqrt(dx * dx + dy * dy);
    
    double d1, d2;
    if (r1 > dist) {
        d1 = r2 + dist;
        d2 = r1;
    }
    else {
        d1 = r1 + r2;
        d2 = dist;
    }

    if (d1 > d2) {
        cout << "2\n";
    }
    else if (d1 < d2) {
        cout << "0\n";
    }
    else {
        cout << "1\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) { solve(); }
    return 0;
}