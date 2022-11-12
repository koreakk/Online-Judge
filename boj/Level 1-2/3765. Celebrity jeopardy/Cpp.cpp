#include <iostream>
#include <string>
using namespace std;

void solve() {
    string s;
    while (getline(cin, s)) {
        cout << s << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}