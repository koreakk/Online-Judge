#include <bits/stdc++.h>
using namespace std;

bool prime[1000000];

void prime_compute() {
    prime[0] = prime[1] = true;
    for (int i = 2; i * i < 1000000; ++i) {
        for (int j = i * i; j < 1000000; j += i) {
            prime[j] = true;
        }
    }
}

void solve() {
    prime_compute();
    
    vector<int> A;
    for (int i = 3; i < 1000000; ++i) {
        if (prime[i]) { continue; }
        A.push_back(i);
    }

    int n;
    while (true) {
        cin >> n;
        if (n == 0) { break; }

        bool find = false;
        for (int a : A) {
            int b = n - a;
            if (prime[b]) { continue; }

            cout << n << " = " << a << " + " << b << '\n';
            find = true;
            break;
        }

        if (!find) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}