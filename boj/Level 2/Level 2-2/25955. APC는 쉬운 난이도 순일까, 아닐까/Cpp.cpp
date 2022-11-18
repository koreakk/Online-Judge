#include <iostream>
#include <string>
using namespace std;

bool compare(const string& l, const string& r) {
    for (const char t : "BSGPO")  {
        if (t == l[0] && t == r[0]) break;
        if (t == l[0]) return true;
        if (t == r[0]) return false;
    }

    int ln = 0, rn = 0;
    for (int i = 1; i < l.size(); ++i) {
        ln = (ln * 10) + (l[i] - '0');
    }

    for (int i = 1; i < r.size(); ++i) {
        rn = (rn * 10) + (r[i] - '0');
    }
    return ln > rn;
}

string arr[1001];

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int idx = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (!compare(arr[i], arr[i + 1])) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "OK\n";
        return;
    }

    cout << "KO\n";
    for (int i = idx + 1; i < n; ++i) {
        if (compare(arr[idx], arr[i])) {
            cout << arr[i - 1] << ' ' << arr[idx] << '\n';
            return;
        }
    }
    cout << arr[n - 1] << ' ' << arr[idx] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}