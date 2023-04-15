#include <bits/stdc++.h>
using namespace std;

int A[1001];

int main() {
    for (int i=0, j=1, k=1; i<=1000; ++i) {
        A[i]=j;
        if (--k==0) {
            ++j;
            k=j;
        }
    }

    int s, e;
    cin >> s >> e;

    int ret=0;
    for (int i=s-1; i<e; ++i) {
        ret+=A[i];
    }

    cout << ret << '\n';
    return 0;
}
