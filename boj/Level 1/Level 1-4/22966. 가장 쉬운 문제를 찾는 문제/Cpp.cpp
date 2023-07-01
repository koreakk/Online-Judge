#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    string r;
    int m = 5;

    while (t--) {
        string s;
        int n;

        cin >> s >> n;
        if (n < m || (n == m && s < r)) {
            r = s;
            m = n;
        }
    }
    
    cout << r << '\n';
    return 0;
}