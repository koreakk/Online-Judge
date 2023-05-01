#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int t;
    cin >> str >> t;

    list<char> data(str.begin(), str.end());
    auto cursor = data.end();

    for (int i = 0; i < t; i++) {
        char c;
        cin >> c;

        if (c == 'L') {
            if (cursor != data.begin()) {
                --cursor;
            }
        }

        else if (c == 'D') {
            if (cursor != data.end()) {
                ++cursor;
            }
        }

        else if (c == 'B') {
            if (cursor != data.begin()) {
                cursor = data.erase(--cursor);
            }

        }

        else if (c == 'P') {
            char ch;
            cin >> ch;

            data.insert(cursor, ch);
        }
    }

    for (auto i = data.begin(); i != data.end(); ++i) {
        cout << *i;
    }
    cout << '\n';

    return 0;
}
