#include <bits/stdc++.h>
using namespace std;

int A[101][101];

int main() {
    int x1, y1, x2, y2;
    
    for (int i = 0; i < 4; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; ++y) {
            for (int x = x1; x < x2; ++x) {
                A[y][x] = 1;
            }
        }
    }

    int ret = 0;
    for (int y = 0; y <= 100; ++y) {
        for (int x = 0; x <= 100; ++x) {
            ret += A[y][x];
        }
    }

    cout << ret << '\n';
    return 0;
}
