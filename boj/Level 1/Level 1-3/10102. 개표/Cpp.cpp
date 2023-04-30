#include <bits/stdc++.h>
using namespace std;

int main() {
    int v;
    string s;
    cin >> v >> s;

    int A = count(s.cbegin(), s.cend(), 'A');
    int B = count(s.cbegin(), s.cend(), 'B');

    if      (A > B) { cout << "A\n";   }
    else if (A < B) { cout << "B\n";   }
    else            { cout << "Tie\n"; }

    return 0;
}
