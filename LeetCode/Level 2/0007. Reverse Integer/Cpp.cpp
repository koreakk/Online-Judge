class Solution {
    enum {
        MIN = static_cast<int>(0x80000000) / 10,
        MAX = static_cast<int>(0x7FFFFFFF) / 10
    };
    
public:
    int reverse(int x) {
        int answer = 0;
        
        for (; x; x /= 10) {
            int digit = x % 10;
            
            if ((answer > MAX || (answer == MAX && digit >  7)) ||
                (answer < MIN || (answer == MIN && digit < -8)))
            {
                answer = 0;
                break;
            }
            
            answer = (answer * 10) + digit;
        }
        return answer;
    }
};