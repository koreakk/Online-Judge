#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    
    map<string, bool> mp;
    mp["ChongChong"] = true;

    int ret = 1;
    for (int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;

        if (mp.find(a) == mp.end()) {
            mp[a] = false;
        }
        if (mp.find(b) == mp.end()) {
            mp[b] = false;
        }

        if (mp[a] == true || mp[b] == true) {
            ret += int(mp[a] == 0) + int(mp[b] == 0);
            mp[a] = mp[b] = true;
        }
    }

    cout << ret << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}