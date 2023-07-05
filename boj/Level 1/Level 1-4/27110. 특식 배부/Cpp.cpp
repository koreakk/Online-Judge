#include <iostream>
#include <utility>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    cout << min(a, n) + min(b, n) + min(c, n) << '\n';
    return 0;
}