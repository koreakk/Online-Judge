#include <iostream>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    
    int w = 1, v;
    for (int i = 0; i < t - 1; ++i) {
        cin >> v;
        if (n < v) {
            w = 0;
            break;
        }
    }

    if (w) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }
    return 0;
}