#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    while (getline(cin, str)) {
        for (auto& c : str) {
            switch (c) {
            case 'i': c = 'e'; break;
            case 'e': c = 'i'; break;
            case 'I': c = 'E'; break;
            case 'E': c = 'I'; break;
            default:           break;
            }
        }

        cout << str << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
