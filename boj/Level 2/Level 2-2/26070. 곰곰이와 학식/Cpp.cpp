#include <bits/stdc++.h>
using namespace std;

void solve() {
    int A, B, C,
        X, Y, Z;
    cin >> A >> B >> C;
    cin >> X >> Y >> Z;

    long long r = 0;
    for (int i = 0; i < 2; ++i) {
        if (A < X) {
            r += A;
            Y += (X - A) / 3;
            X  = (X - A) % 3;
            A  = 0;
        }
        else {
            r += X;
            A -= X;
            X  = 0;
        }
        
        if (B < Y) {
            r += B;
            Z += (Y - B) / 3;
            Y  = (Y - B) % 3;
            B  = 0;
        }
        else {
            r += Y;
            B -= Y;
            Y  = 0;
        }
        
        if (C < Z) {
            r += C;
            X += (Z - C) / 3;
            Z  = (Z - C) % 3;
            C  = 0;
        }
        else {
            r += Z;
            C -= Z;
            Z  = 0;
        }
         

    }
    
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}