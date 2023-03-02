#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string young_name;
    int young_age = 0;

    string old_name;
    int old_age = INT_MAX;

    while (n--) {
        string name;
        int d, m, y;

        cin >> name >> d >> m >> y;

        int age = d + (m*30) + (y*365);

        if (age > young_age) {
            young_name = name;
            young_age  = age;
        }

        if (age < old_age) {
            old_name = name;
            old_age  = age;
        }
    }

    cout << young_name << '\n';
    cout << old_name   << '\n';

    return 0;
}
