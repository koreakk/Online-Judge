#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (;;) {
        int x;
        cin >> x;
        if (x == 0) {
            break;
        }
        if ((x%n) == 0) {
            printf("%d is a multiple of %d.\n", x, n);
        }
        else {
            printf("%d is NOT a multiple of %d.\n", x, n);
        }
    }
    return 0;
}