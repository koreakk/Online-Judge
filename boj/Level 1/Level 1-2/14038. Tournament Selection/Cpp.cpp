#include <iostream>
using namespace std;

int main() {
    int w = 0;
    
    for (int i = 0; i < 6; ++i) {
        char c;
        cin >> c;
        w += c == 'W' ? 1 : 0;
    }

    int r[4] = { -1, 3, 2, 1 };
    cout << r[(w + 1) / 2] << '\n';

    return 0;
}