#include <bits/stdc++.h>
using namespace std;

int N, T, A[40];

vector<int> f(const int* begin, const int* end) {
    int N = (int)(end - begin);
    vector<int> ret(1ULL << N);

    for (int i = 0, s = (int)ret.size(); i < s; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) {
                ret[i] += *(begin + j);
            }
        }
    }

    return ret;
}

void solve() {
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int mid = N / 2;
    vector<int> lo = f(A,     A + mid);
    vector<int> hi = f(A + mid, A + N);

    long long result = T == 0 ? -1 : 0;
    sort(hi.begin(), hi.end());

    for (int x : lo) {
        result += (long long)(upper_bound(hi.begin(), hi.end(), T - x) - 
                  lower_bound(hi.begin(), hi.end(), T - x));
    }

    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed; cout.precision(16);
    solve();
    return 0;
}