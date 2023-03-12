#include <bits/stdc++.h>
using namespace std;

map<string, double> grade_table = {
    { "A+"s, 4.5 }, { "A0"s, 4.0 },
    { "B+"s, 3.5 }, { "B0"s, 3.0 },
    { "C+"s, 2.5 }, { "C0"s, 2.0 },
    { "D+"s, 1.5 }, { "D0"s, 1.0 },
    { "F"s , 0.0 }
};

int main() {
    string sub_name, grade;
    double credit;

    double sum = 0, ret = 0;

    for (int i = 0; i < 20; ++i) {
        cin >> sub_name >> credit >> grade;
        if (grade == "P") { continue; }

        sum += credit;
        ret += grade_table[grade] * credit; 
    }

    ret /= sum;
    cout << ret << '\n';

    return 0;
}
