#include <bits/stdc++.h>
using namespace std;

int A[200000], N, C;

int f(int x) {
    int ret=1;
    int i=1, j=0;
    for (;i<N; ++i) {
        if (A[i]-A[j] >= x) {
            ++ret;
            j=i;
        }
    }
    return ret;
}

int main() {
    cin >> N >> C;
    for_each(A, A+N, [](int& n) { cin >> n; });

    sort(A, A+N);

    int lo=0, hi=A[N-1]-A[0];
    int mid=0;

    while (lo<=hi) {
        mid=lo+(hi-lo)/2;

        if (C>f(mid)) { hi=mid-1; }
        else          { lo=mid+1; }
    }

    cout << hi << '\n';
}
