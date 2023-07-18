#include <iostream>
using namespace std;

int main() {
    int A[4] = { 0, 1, 0, 0 };
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        swap(A[x], A[y]);
    }
    for (int i = 1; i <= 3; ++i) {
        if (A[i] == 1) {
            cout << i << '\n';
        }
    }
    return 0;
}