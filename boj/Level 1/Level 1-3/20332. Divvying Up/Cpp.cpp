#include <iostream>
using namespace std;

int main() {
    int n, x, s = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        s += x;
    }
    cout << (s % 3 ? "no\n" : "yes\n");
    return 0;
}