#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral" << endl;
    } else if (a + b + c == 180) {
        if (a != b && b != c && a != c) {
            cout << "Scalene" << endl;
        } else {
            cout << "Isosceles" << endl;
        }
    } else {
        cout << "Error" << endl;
    }
    return 0;
}