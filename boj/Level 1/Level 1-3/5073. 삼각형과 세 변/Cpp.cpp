#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a==0 && b==0 && c==0) {
            break;
        }

        if (a >= (b+c) || b >= (a+c) || c >= (a+b)) {
            cout << "Invalid\n";
        }
        else if (a==b && a==c) {
            cout << "Equilateral\n";
        }
        else if (a==b || a==c || b==c) {
            cout << "Isosceles\n";
         }
        else {
            cout << "Scalene\n";
        }
    }

    return 0;
}
