#include <bits/stdc++.h>
using namespace std;

int main() {
    string A;
    cin >> A;

    int ret=10;
    for (int i=1; i < A.length(); ++i) {
        ret += (A[i]==A[i-1]) ? 5 : 10;
    }

    cout << ret << '\n';
    return 0;
}
