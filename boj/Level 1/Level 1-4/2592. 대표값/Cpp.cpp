#include <bits/stdc++.h>
using namespace std;

int A[101];

int main() {
    int sum_num = 0;

    for (int i = 0; i < 10; ++i) {
        int n;
        cin >> n;

        ++A[n/10];
        sum_num += n;
    }

    int mean = sum_num / 10;

    int max_num = 0;
    int mode    = 0;
    
    for (int i = 0; i <= 100; ++i) {
        if (A[i] > max_num) {
            max_num = A[i];
            mode    = i * 10;
        }
    }

    cout << mean << '\n';
    cout << mode << '\n';

    return 0;
}
