#include <bits/stdc++.h>
using namespace std;

int N, T, A[40];

void dfs(vector<int>& in, const int* begin, const int* end, int s = 0) {
    if (begin >= end) {
        in.push_back(s);
        return;
    }
    dfs(in, begin + 1, end, s + *begin);
    dfs(in, begin + 1, end, s);
}

void solve() {
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int m = N / 2;
    vector<int> lo; dfs(lo, A,     A + m);
    vector<int> hi; dfs(hi, A + m, A + N);

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
    solve();
    return 0;
}