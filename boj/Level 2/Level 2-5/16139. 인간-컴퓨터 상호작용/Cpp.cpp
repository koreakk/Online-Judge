#include <bits/stdc++.h>
using namespace std;

int A[200001][26];

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    int len = (int)str.length();

    for (int i = 0; i < len; ++i) {
        ++A[i+1][str[i] - 'a'];
    }
    
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < 26; ++j) {
            A[i][j] += A[i-1][j];
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char q;
        int l, r;
        cin >> q >> l >> r;

        int j = q - 'a';
        cout << A[r+1][j] - A[l][j] << '\n';
    }

    return 0;
}
