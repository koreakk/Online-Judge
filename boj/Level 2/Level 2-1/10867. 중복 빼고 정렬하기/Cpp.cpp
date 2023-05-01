#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for_each(v.begin(), v.end(), [](int& p) { cin >> p; });

    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());

    for_each(v.begin(), end, [](int p) { cout << p << ' '; });
    cout << '\n';

    return 0;
}
