#include <iostream>
using namespace std;

int main() {
    int y0, m0, d0;
    int y1, m1, d1;

    cin >> y0 >> m0 >> d0;
    cin >> y1 >> m1 >> d1;

    int age = y1 - y0;
    if (m0 < m1 || (m0 == m1 && d0 <= d1)) {
        cout << age << '\n';
    }
    else {
        cout << age - 1 << '\n';
    }
    cout << age + 1 << '\n';
    cout << age << '\n';

    return 0;
}