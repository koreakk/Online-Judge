#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int X, Y;
    while (n--) {
        cin >> X >> Y;

        if (X < Y) { cout << "NO BRAINS\n";  }
        else       { cout << "MMM BRAINS\n"; }
    }
    
    return 0;
}
