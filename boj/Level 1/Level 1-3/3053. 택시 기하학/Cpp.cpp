#include <iostream>
#include <cmath>
using namespace std;

constexpr double PI = 3.14159265359;

int main() {
    cout << fixed;
    cout.precision(6);

    double r;
    cin >> r;

    cout << r * r * PI  << '\n';
    cout << r * r * 2.0 << '\n';

    return 0;
}