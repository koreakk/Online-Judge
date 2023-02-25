#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> sti(const string& t) {
    int h = 10*(t[0]-'0') + t[1]-'0';
    int m = 10*(t[3]-'0') + t[4]-'0';
    int s = 10*(t[6]-'0') + t[7]-'0';

    return { h, m, s };
}

string its(int h, int m, int s) {
    string t;

    t = t + char(h/10+'0') + char(h%10+'0') + ':';
    t = t + char(m/10+'0') + char(m%10+'0') + ':';
    t = t + char(s/10+'0') + char(s%10+'0');
 
    return t;
}

int main() {
    string t1, t2;
    cin >> t1 >> t2;

    auto [h1, m1, s1] = sti(t1);
    auto [h2, m2, s2] = sti(t2);

    int h = h2 - h1;
    int m = m2 - m1;
    int s = s2 - s1;

    if (s < 0) { s += 60, m -= 1; }
    if (m < 0) { m += 60, h -= 1; }
    if (h < 0) { h += 24;         }

    cout << its(h, m, s) << '\n';

    return 0;
}
