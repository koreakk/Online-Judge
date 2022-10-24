#include <cctype>
#include <climits>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool sign = true;
        int value = 0;
        
        auto iter = s.cbegin();
        auto end  = s.cend();
        for (; iter != end && isspace(*iter); ++iter) {}
        
        if (!isdigit(*iter)) {
            if ((*iter) == '-' || (*iter) == '+') {
                sign = static_cast<bool>((*iter) == '+');
                ++iter;
            }
            else {
                return 0;
            }
        }
        
        for (; iter != end && isdigit(*iter); ++iter) {
            int digit = (*iter) - '0';

            if (value > (INT_MAX / 10) || value == (INT_MAX / 10) && digit > 7) {
                return sign ? INT_MAX : INT_MIN;
            }

            value = (value * 10) + digit;
        }
        
        value = sign ? value : -value;
        return value;
    }
};