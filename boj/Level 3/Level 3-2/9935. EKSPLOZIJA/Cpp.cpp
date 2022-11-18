#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsSameString(const vector<char>& Stack, int StackIdx, const string& p) {
    const int length = (int)p.length();
    
    int i = 0;
    int j = StackIdx - length + 1;
    if (j < 0) return false;

    for (; i < length; ++i, ++j) {
        if (p[i] != Stack[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s, p;
    cin >> s >> p;

    const int s_len = (int)s.length();
    const int p_len = (int)p.length();

    vector<char> Stack(s_len);
    int Idx = -1;

    for (char ch : s) {
        Stack[++Idx] = ch;
        
        if (IsSameString(Stack, Idx, p)) {
            Idx -= p_len;
        }
    }

    if (Idx < 0) {
        cout << "FRULA" << endl;
    }
    else {
        for (int i = 0; i <= Idx; ++i) {
            cout << Stack[i];
        }
        cout << endl;
    }

    return 0;
}