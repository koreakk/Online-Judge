#include <bits/stdc++.h>
using namespace std;

bool prime[10000];

void prime_compute() {
    prime[0] = prime[1] = true;
    for (int i = 2; i * i < 10000; ++i) {
        for (int j = i * i; j < 10000; j += i) {
            prime[j] = true;
        }
    }
}

void solve() {
    prime_compute();
    
    vector<int> A;
    for (int i = 2; i < 10000; ++i) {
        if (prime[i]) { continue; }
        A.push_back(i);
    }

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        int a(0), b(0);
        for (int i = 0; A[i] <= n - A[i]; ++i) {
            if (prime[n - A[i]]) { continue; }
            a = A[i], b = n - A[i];
        }

        cout << a << ' ' << b << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}