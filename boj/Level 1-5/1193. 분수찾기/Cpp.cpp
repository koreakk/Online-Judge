#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x;
    cin >> x;

    int i = 1, j = x;
    for (; j > i; j -= i++) {}
    
    if (i % 2) {
        cout << i + 1 - j << '/' << j << endl;
    } else {
        cout << j << '/' << i + 1 - j << endl;
    }
    return 0;
}