#include <bits/stdc++.h>
using namespace std;

void f(vector<char>::iterator begin, vector<char>::iterator end) {
    vector<char>::difference_type dist = distance(begin, end);

    if (dist == 1) {
        (*begin) = '-';
        return;
    }

    vector<char>::iterator d1 = begin;
    advance(d1, dist/3);

    vector<char>::iterator d2 = d1;
    advance(d2, dist/3);

    f(begin, d1);
    f(d2,   end);
}

int main() {
    int n;

    while (cin >> n) {
        vector<char> l(pow<int>(3, n), ' ');
        f(l.begin(), l.end());

        for (auto p : l) { cout << p; }
        cout << '\n';
    }

    return 0;
}
