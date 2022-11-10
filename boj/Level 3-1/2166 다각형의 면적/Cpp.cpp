#include <iostream>
using namespace std;

int N, X[100000], Y[100000];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    double area = 0;
    for (int i = 0, j = N - 1; i < N; j = i++) {
        area += (double)(X[j] + X[i]) * (Y[j] - Y[i]) / 2;
    }

    cout << abs(area) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(1);
    solve();
    return 0;
}
