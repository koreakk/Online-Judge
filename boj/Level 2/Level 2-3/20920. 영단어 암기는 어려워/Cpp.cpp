#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;
    string word;

    for (int i = 0; i < n; ++i) {
        cin >> word;
        if (word.length() >= m) {
            ++mp[word];
        }
    }

    vector<pair<string, int>> v(mp.begin(), mp.end());

    sort(
        v.begin(),
        v.end(),
        [](const pair<string, int>& l, const pair<string, int>& r) -> bool {
            if (l.second == r.second) {
                const size_t l_len = l.first.length();
                const size_t r_len = r.first.length();

                return l_len > r_len || (l_len == r_len && l.first < r.first);
            }
            return l.second > r.second;
        }        
    );

    for (auto x : v) {
        cout << x.first << '\n';
    }

    return 0;
}
