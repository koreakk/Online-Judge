#include <bits/stdc++.h>
using namespace std;

bool inCircle(int x, int y, int cx, int cy, int r) {
    int dx = x - cx;
    int dy = y - cy;

    int d = dx * dx + dy * dy;
    return d <= r * r;
}

void solve() {
    int x1, y1;
    cin >> x1 >> y1;

    int x2, y2;
    cin >> x2 >> y2;
    
    int n;
    cin >> n;

    int ret = 0;
    while (n--) {
        int cx, cy, r;
        cin >> cx >> cy >> r;

        bool in1 = inCircle(x1, y1, cx, cy, r);
        bool in2 = inCircle(x2, y2, cx, cy, r);

        if ((in1 || in2) && (in1 != in2)) {
            ++ret;
        }
    }

    cout << ret << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) { solve(); }
    return 0;
}									