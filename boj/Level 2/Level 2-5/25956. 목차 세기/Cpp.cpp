#include <iostream>
#include <string>
using namespace std;

int arr[1000001], N;
int res[1000001];

int f(int i) {
    while (true) {
        int j = i + 1;
        while (j < N && arr[i] + 1 == arr[j]) {
            ++res[i];
            j = f(j);
        }

        if (j < N && arr[j] == 1) {
            i = j;
            continue;
        }
        return j;
    }
}

void solve() {
    cin >> N;

    bool b = true;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        if (i == 0 && arr[i] != 1) {
            b = false;
            continue;
        }

        else if (arr[i] > arr[i - 1] && arr[i] - arr[i - 1] != 1) {
            b = false;
        }
    }

    if (b == false) cout << -1 << '\n';
    else {
        f(0);
        for (int i = 0; i < N; ++i)
            cout << res[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}