#include <bits/stdc++.h>
using namespace std;

int A[80], N;

int check(int i, int n) {
    int j=i-1;
    while (j>=i-j-1) {
        if (A[j]!=n) {
            --j;
            continue;
        }

        int  l=i-j, k=i, c=0;
        while (--l&&!c) {
            if (A[--j]!=A[--k]) {
                c=1;
                break;
            }
        }

        if (!c) {
            return 0;
        }
    }

    return 1;
}

int solve(int i) {
    if (i==N) {
        return 1;
    }

    for (int n=1; n<=3; ++n) {
        if (!check(i, n)) {
            continue;
        }

        A[i]=n;
        if (solve(i+1)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> N;
    solve(0);
    for (int i=0; i<N; ++i) {
        cout << A[i];
    }
    cout << '\n';
    return 0;
}
