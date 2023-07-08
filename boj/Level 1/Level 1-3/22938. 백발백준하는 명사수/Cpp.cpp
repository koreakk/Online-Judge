#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ll x1, y1, r1;
    ll x2, y2, r2;
    
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    
    ll dx = (x1 - x2);
    ll dy = (y1 - y2);
    
    ll d1 = dx * dx + dy * dy;
    ll d2 = (r1 + r2) * (r1 + r2);
    
    if (d1 >= d2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
    
    return 0;
}