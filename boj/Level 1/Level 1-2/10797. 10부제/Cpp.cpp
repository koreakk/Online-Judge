#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ret = 0;
    for (int i = 0; i < 5; ++i) {
        int x; cin >> x;
        ret += x == n ? 1 : 0;
    }

    cout << ret << '\n';
    return 0;
}