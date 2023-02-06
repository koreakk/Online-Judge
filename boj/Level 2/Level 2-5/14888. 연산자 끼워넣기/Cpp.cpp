#include <bits/stdc++.h>
using namespace std;

int A[11], N;
int OP[4];

int max_num = -1000000000;
int min_num = 1000000000;

int calc(int a, int b, int op) {
    switch (op) {
    case 0: return a + b;
    case 1: return a - b;
    case 2: return a * b;
    case 3: return a / b;
    default: return -1;
    }
}

void f(int i, int x) {
    if (i == N - 1) {
        max_num = max(max_num, x);
        min_num = min(min_num, x);
        return;
    }

    for (int op = 0; op < 4; ++op) {
        if (OP[op] == 0) { continue; }
        
        --OP[op];
        f(i + 1, calc(x, A[i + 1], op));
        ++OP[op];
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < 4; ++i) {
        cin >> OP[i];
    }

    f(0, A[0]);

    cout << max_num << '\n';
    cout << min_num << '\n';

    return 0;
}
