#include <bits/stdc++.h>
using namespace std;

int main() {
    int total;
    cin >> total;

    for (int i = 0; i < 9; ++i) {
        int cost;
        cin >> cost;

        total -= cost;
    }

    cout << total << '\n';
    return 0;
}
