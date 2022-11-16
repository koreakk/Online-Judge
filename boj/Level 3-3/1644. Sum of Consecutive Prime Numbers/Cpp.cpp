#include <iostream>
using namespace std;

bool primeArray[4000001];

void InitPrimeNumber(int N) {
    for (int i = 2; i <= N; ++i) {
        primeArray[i] = true;
    }

    for (int i = 2; i * i <= N; ++i) {
        if (primeArray[i]) {
            for (int j = i * i; j <= N; j += i) {
                primeArray[j] = false;
            }
        }
    }
}

void solve() {
    int N; cin >> N;
    InitPrimeNumber(N);

    int result = 0;
    int sum    = 0;
    int l = 2, r = 2;
    while (true) {
        while (!primeArray[l] && l <= N) ++l;
        while (!primeArray[r] && r <= N) ++r;

        if (l > N || r > N) break;

        if (sum + r == N) {
            ++result;
            sum -= l++;
            sum += r++;
        }
        else if (sum + r > N) {
            sum -= l++;
        }
        else {
            sum += r++;
        }
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}