#include <bits/stdc++.h>
using namespace std;

int A[50], B[50], N;

int main() {
    cin >> N;
    
    for_each(A, A+N, [](int& n) { cin >> n; });
    for_each(B, B+N, [](int& n) { cin >> n; });

    sort(A, A+N, greater<int>{});
    sort(B, B+N, less<int>{});

    int ret=0;
    for (int i=0; i<N; ++i) {
        ret += A[i]*B[i];
    }

    cout << ret << '\n';
}
