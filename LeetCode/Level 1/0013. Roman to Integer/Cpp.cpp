#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<char, int> symbols = {
        { 'I', 1    },
        { 'V', 5    },
        { 'X', 10   },
        { 'L', 50   },
        { 'C', 100  },
        { 'D', 500  },
        { 'M', 1000 }
    };

    int romanToInt(string s) {
        int ret = 0;
        int len = (int)s.length();

        for (int i = 0; i < len-1; ++i) {
            int l = symbols[s[i]];
            int r = symbols[s[i+1]];
            
            if (l < r) { ret -= l; }
            else       { ret += l; }
        }

        ret += symbols[s[len-1]];

        return ret;
    }
};