#include <iostream>
#include <string>
using namespace std;

string f(string::const_iterator &it) {
    char h = (*it);
    ++it;

    if (h == 'b') { return string("b"); }
    if (h == 'w') { return string("w"); }

    string lu = f(it);
    string ru = f(it);
    string ld = f(it);
    string rd = f(it);

    return string("x") + ld + rd + lu + ru;
}

int main() {
    int t;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;
        auto it = s.cbegin();

        cout << f(it) << '\n';
    }

    return 0;
}
