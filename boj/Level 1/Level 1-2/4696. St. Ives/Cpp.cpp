#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << fixed;
    cout.precision(2);

    for (;;) {
        double n;
        cin >> n;
        
        if (n == 0) {
            break;
        }

        cout << 1 + n + pow(n, 2) \
               + pow(n, 3) + pow(n, 4) << '\n';
    }

    return 0;
}