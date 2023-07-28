#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n > b || a < b) {
        cout << "Bus\n";
    }
    else if (a > b) {
        cout << "Subway\n";
    }
    else {
        cout << "Anything\n";
    }
    return 0;
}