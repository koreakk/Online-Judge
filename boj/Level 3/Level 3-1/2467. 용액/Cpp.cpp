#include <iostream>
using namespace std;

int N, arr[100001];

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int l = 0, r = N - 1;
    int resl = arr[l], resr = arr[r];
    while (l < r) {
        int x = arr[l] + arr[r];

        if (abs(resl + resr) > abs(x)) {
            resl = arr[l], resr = arr[r];
        }

        if (x < 0) ++l;
        else       --r;
    }

    cout << resl << ' ' << resr << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}