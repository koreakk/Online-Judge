#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int l;
    string s;
    cin >> l >> s;

    int e = count(begin(s), end(s), 'e');

    if (e > l - e) {
        cout << "e\n";
    }
    else if (e < l - e) {
        cout << "2\n";
    }
    else {
        cout << "yee\n";
    }

    return 0;
}