#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int max_cost = 0, cost;
        string name, s;

        while (n--) {
            cin >> cost >> s;

            if (cost > max_cost) {
                max_cost = cost;
                name = s;
            }
        }

        cout << name << '\n';
    }

    return 0;
}
