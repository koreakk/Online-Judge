#include <iostream>
#include <utility>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    cout << n * 3000 - min(n, (k + 60)) * 1500 << '\n';
    return 0;
}