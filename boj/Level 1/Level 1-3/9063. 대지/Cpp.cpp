#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i].first >> A[i].second;
    }

    if(n == 1) {
        cout << "0\n";
        return 0;
    }

    int max_x = INT_MIN, min_x = INT_MAX;
    int max_y = INT_MIN, min_y = INT_MAX;

    for (int i = 0; i < n; ++i) {
        max_x = max(max_x, A[i].first);
        min_x = min(min_x, A[i].first);
        max_y = max(max_y, A[i].second);
        min_y = min(min_y, A[i].second);
    }

    cout << (max_x-min_x) * (max_y-min_y) << '\n';
    return 0;
}
