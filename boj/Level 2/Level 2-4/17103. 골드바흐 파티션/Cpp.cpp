#include <bits/stdc++.h>
using namespace std;
int A[1000001], B[1000001];

int main() {
    A[0]=A[1]=1;
    for (int i=2; i*i<=1000000; ++i) {
        if (A[i]) { continue; }
        for (int j=i*i; j<=1000000; j+=i) {
            A[j]=1;
        }
    }

    for (int i=0,j=0; i<=1000000; ++i) {
        if (!A[i]) { B[j++] = i; }
    }

    int t;
    cin >> t;

    for (;t--;) {
        int n;
        cin >> n;

        int ret=0;
        for (int i=0; B[i]<=n-B[i]; ++i) {
            if (!A[n-B[i]]) { ++ret; }
        }

        cout << ret << '\n';
    }

    return 0;
}
