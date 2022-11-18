#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    for (int t = 1;; ++t) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; ++i)
            cin >> x;

        cout << "Case " << t << ": Sorting... done!" << endl;
    }

    return 0;
}
