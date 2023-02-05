#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int first_ling;
    cin >> first_ling;

    for (int i = 1; i < n; ++i) {
        int ling;
        cin >> ling;

        int g = gcd(first_ling, ling);
        cout << first_ling / g << '/' << ling / g << '\n'; 
    }
    
    return 0;
}
