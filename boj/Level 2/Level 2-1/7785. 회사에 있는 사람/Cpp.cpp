#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> mp;
    string name, info;

    for (int i = 0; i < n; ++i) {
        cin >> name >> info;
        if (info == "enter") { mp[name]=1; }
        else                 { mp[name]=0; }
    }

    for (auto it=mp.rbegin(); it!=mp.rend(); ++it) {
        if (it->second) { cout << it->first << '\n'; }
    }

    return 0;
}
